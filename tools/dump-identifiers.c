/*
 * dump-identifiers.c --
 *
 *      Operations to dump flat identifier lists for SMI modules.
 *
 * Copyright (c) 2000 Frank Strauss, Technical University of Braunschweig.
 * Copyright (c) 2000 J. Schoenwaelder, Technical University of Braunschweig.
 *
 * See the file "COPYING" for information on usage and redistribution
 * of this file, and for a DISCLAIMER OF ALL WARRANTIES.
 *
 * @(#) $Id: dump-identifiers.c,v 1.15 2002/10/30 09:17:37 schoenw Exp $
 */

#include <config.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "smi.h"
#include "smidump.h"


static int moduleLen = 0;
static int identifierLen = 0;

static int ignoretypes = 0;
static int ignorenodes = 0;
static int showlines = 0;
static int showpath = 0;


static char *smiStringNodekind(SmiNodekind nodekind)
{
    return
        (nodekind == SMI_NODEKIND_UNKNOWN)      ? "<unknown>" :
        (nodekind == SMI_NODEKIND_NODE)         ? "node" :
        (nodekind == SMI_NODEKIND_SCALAR)       ? "scalar" :
        (nodekind == SMI_NODEKIND_TABLE)        ? "table" :
        (nodekind == SMI_NODEKIND_ROW)          ? "row" :
        (nodekind == SMI_NODEKIND_COLUMN)       ? "column" :
        (nodekind == SMI_NODEKIND_NOTIFICATION) ? "notification" :
        (nodekind == SMI_NODEKIND_GROUP)        ? "group" :
        (nodekind == SMI_NODEKIND_COMPLIANCE)   ? "compliance" :
        (nodekind == SMI_NODEKIND_CAPABILITIES) ? "capabilities" :
                                                  "<UNDEFINED>";
}



static void fprintNodeIdentifiers(FILE *f, int modc, SmiModule **modv)
{
    SmiNode      *smiNode;
    unsigned int j;
    int          i;

    for (i = 0; i < modc; i++) {
	for (smiNode = smiGetFirstNode(modv[i], SMI_NODEKIND_ANY);
	     smiNode;
	     smiNode = smiGetNextNode(smiNode, SMI_NODEKIND_ANY)) {
	    if (smiNode->name) {
		fprintf(f, "%*s",
			-moduleLen, showpath ? modv[i]->path : modv[i]->name);
		if (showlines) {
		    fprintf(f, ":%d:", smiGetNodeLine(smiNode));
		}
		fprintf(f, " %*s %-12s ", -identifierLen, smiNode->name,
			smiStringNodekind(smiNode->nodekind));
		for (j = 0; j < smiNode->oidlen; j++) {
		    fprintf(f, j ? ".%u" : "%u", smiNode->oid[j]);
		}
		fprintf(f, "\n");
	    }
	}
    }
}



static void fprintTypeIdentifiers(FILE *f, int modc, SmiModule **modv)
{
    SmiType   *smiType;
    int	      i;

    for (i = 0; i < modc; i++) {
	for (smiType = smiGetFirstType(modv[i]);
	     smiType;
	     smiType = smiGetNextType(smiType)) {
	    if (smiType->name) {
		fprintf(f, "%*s",
			-moduleLen, showpath ? modv[i]->path : modv[i]->name);
		if (showlines) {
		    fprintf(f, ":%d:", smiGetTypeLine(smiType));
		}
		fprintf(f, " %*s %-12s\n", -identifierLen, smiType->name,
			"type");
	    }
	}
    }
}



static void dumpIdentifiers(int modc, SmiModule **modv, int flags,
			    char *output)
{
    SmiNode   *smiNode;
    int	      i, len;
    FILE      *f = stdout;

    if (output) {
	f = fopen(output, "w");
	if (!f) {
	    fprintf(stderr, "smidump: cannot open %s for writing: ", output);
	    perror(NULL);
	    exit(1);
	}
    }

    for (moduleLen = 0, identifierLen = 0, i = 0; i < modc; i++) {
	if (showpath) {
	    len = strlen(modv[i]->path);
	} else {
	    len = strlen(modv[i]->name);
	}
	if (len > moduleLen) moduleLen = len;
	for (smiNode = smiGetFirstNode(modv[i], SMI_NODEKIND_ANY);
	     smiNode;
	     smiNode = smiGetNextNode(smiNode, SMI_NODEKIND_ANY)) {
	    if (smiNode->name) {
		len = strlen(smiNode->name);
		if (len > identifierLen) identifierLen = len;
	    }
	}
    }

    if (flags & SMIDUMP_FLAG_UNITE) {

	if (! (flags & SMIDUMP_FLAG_SILENT)) {
	    fprintf(f, "# united list of identifiers (generated by smidump "
		    SMI_VERSION_STRING ")\n\n");
	}

	if (!ignoretypes) {
	    fprintTypeIdentifiers(f, modc, modv);
	}
	
	if (!ignorenodes) {
	    fprintNodeIdentifiers(f, modc, modv);
	}

    } else {

	for (i = 0; i < modc; i++) {

	    if (! (flags & SMIDUMP_FLAG_SILENT)) {
		fprintf(f, "# %s list of identifiers (generated by smidump "
			SMI_VERSION_STRING ")\n\n",
			modv[i]->name);
	    }

	    if (!ignoretypes) {
		fprintTypeIdentifiers(f, 1, &(modv[i]));
	    }

	    if (!ignorenodes) {
		fprintNodeIdentifiers(f, 1, &(modv[i]));
	    }
	}
    }

    if (fflush(f) || ferror(f)) {
	perror("smidump: write error");
	exit(1);
    }

    if (output) {
	fclose(f);
    }
}



void initIdentifiers()
{
    
    static SmidumpDriverOption opt[] = {
	{ "ignore-types", OPT_FLAG, &ignoretypes, 0,
	  "do not dump types"},
	{ "ignore-nodes", OPT_FLAG, &ignorenodes, 0,
	  "do not dump nodes"},
	{ "show-lines", OPT_FLAG, &showlines, 0,
	  "show line numbers"},
	{ "show-path", OPT_FLAG, &showpath, 0,
	  "show file path instead of module name"},
        { 0, OPT_END, 0, 0 }
    };

    static SmidumpDriver driver = {
	"identifiers",
	dumpIdentifiers,
	SMI_FLAG_NODESCR,
	0,
	"list of all identifiers",
	opt,
	NULL
    };
    
    smidumpRegisterDriver(&driver);
}
