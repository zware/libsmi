/*
 * dump-imports.c --
 *
 *      Operations to dump import hierarchies in a human readable format.
 *
 * Copyright (c) 1999 Frank Strauss, Technical University of Braunschweig.
 * Copyright (c) 1999 J. Schoenwaelder, Technical University of Braunschweig.
 *
 * See the file "COPYING" for information on usage and redistribution
 * of this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * @(#) $Id: dump-imports.c,v 1.18 2000/12/11 08:41:22 strauss Exp $
 */

#include <config.h>

#include <stdio.h>
#include <string.h>

#include "smi.h"
#include "smidump.h"


typedef struct Imports {
    char *module;
    char *name;
    int  count;
    struct Imports *nextPtr;
} Imports;



static Imports *getImports(SmiModule *smiModule, int *n)
{
    SmiImport *smiImport;
    Imports   *imports;
    int       i;
    size_t    size;
    
    for(smiImport = smiGetFirstImport(smiModule), *n = 0;
	smiImport; smiImport = smiGetNextImport(smiImport)) {
	(*n)++;
    }

    size = (*n + 1) * sizeof(Imports);
    imports = xmalloc(size);
    memset(imports, 0, size);

    for(smiImport = smiGetFirstImport(smiModule), *n = 0;
	smiImport; smiImport = smiGetNextImport(smiImport)) {
	
	for (i = 0; i < *n; i++) {
	    if (strcmp(smiImport->module, imports[i].module) == 0) {
		break;
	    }
	}
	
	if (i == *n) {
	    imports[i].module = xstrdup(smiImport->module);
	    if (imports[i].module) {
		imports[i].count = 0;
		(*n)++;
	    }
	}
	imports[i].count++;
    }

    return imports;
}



static void freeImports(Imports *imports, int n)
{
    int i;

    for (i = 0; i < n; i++) {
	xfree(imports[i].module);
    }

    xfree(imports);
}



static int fprintImports(FILE *f, SmiModule *smiModule, char *prefix,
			 Imports *backtrace)
{
    SmiModule *smiModule2;
    Imports *imports, *imp;
    int     i, n, recurse = 0, done = 0;

    for (imp = backtrace; imp; imp = imp->nextPtr) {
	if (strcmp(imp->module, smiModule->name) == 0) {
	    fprintf(stderr, "%s  (recursion - aborted)\n", prefix);
	    return 0;
	}
    }

    imp = (Imports *) xmalloc(sizeof(Imports));
    imp->module = smiModule->name;
    imp->nextPtr = backtrace;
    backtrace = imp;

    imports = getImports(smiModule, &n);

    for (i = 0; i < n; i++) {
	char *newprefix;

	smiModule2 = smiGetModule(imports[i].module);
	recurse = (NULL == smiGetFirstImport(smiModule2));
	if (recurse) {
	    fprintf(f, "%s  |\n", prefix);
	}
	fprintf(f, "%s  +--%s [%d identifier%s]\n", prefix, imports[i].module, 
		imports[i].count, imports[i].count > 1 ? "s" : "");
	newprefix = xmalloc(strlen(prefix)+10);
	strcpy(newprefix, prefix);
	if (i == n-1) {
	    strcat(newprefix, "   ");
	} else {
	    strcat(newprefix, "  |");
	}
	done = fprintImports(f, smiModule2, newprefix, backtrace);
	if (! recurse && done) {
	    if (i == n-1) {
		fprintf(f, "%s   \n", prefix);
	    } else {
		fprintf(f, "%s  |\n", prefix);
	    }
	}
	xfree(newprefix);
    }

    freeImports(imports, n);
    xfree(backtrace);

    return recurse;
}



static void dumpImports(int modc, SmiModule **modv, int flags, char *output)
{
    int  i;
    FILE *f = stdout;
    
    if (output) {
	f = fopen(output, "w");
	if (!f) {
	    fprintf(stderr, "smidump: cannot open %s for writing: ", output);
	    perror(NULL);
	    exit(1);
	}
    }

    for (i = 0; i < modc; i++) {
	if (! (flags & SMIDUMP_FLAG_SILENT)) {
	    fprintf(f, "# %s imports tree (generated by smidump "
		    SMI_VERSION_STRING ")\n\n", modv[i]->name);
	}

	fprintf(f, "%s\n", modv[i]->name);
	fprintImports(f, modv[i], "", NULL);
    }

    if (output) {
	fclose(f);
    }
}



void initImports()
{
    
    static SmidumpDriver driver = {
	"imports",
	dumpImports,
	SMI_FLAG_NODESCR,
	SMIDUMP_DRIVER_CANT_UNITE,
	"recursive list of all imports",
	NULL,
	NULL
    };
    
    smidumpRegisterDriver(&driver);
}
