/*
 * This Java file has been generated by smidump 0.2.13. Do not edit!
 * It is intended to be used within a Java AgentX sub-agent environment.
 *
 * $Id$
 */

/**
    This class represents a Java AgentX (JAX) implementation of
    the table usrHistoryObjectTable defined in RMON2-MIB.

    @version 1
    @author  smidump 0.2.13
    @see     AgentXTable
 */

import java.util.Vector;

import jax.AgentXOID;
import jax.AgentXVarBind;
import jax.AgentXResponsePDU;
import jax.AgentXSetPhase;
import jax.AgentXTable;
import jax.AgentXEntry;

public class UsrHistoryObjectTable extends AgentXTable
{

    // entry OID
    private final static long[] OID = {1, 3, 6, 1, 2, 1, 16, 18, 2, 1};

    // constructors
    public UsrHistoryObjectTable()
    {
        oid = new AgentXOID(OID);

        // register implemented columns
        columns.addElement(new Long(2));
        columns.addElement(new Long(3));
    }

    public UsrHistoryObjectTable(boolean shared)
    {
        super(shared);

        oid = new AgentXOID(OID);

        // register implemented columns
        columns.addElement(new Long(2));
        columns.addElement(new Long(3));
    }

    public AgentXVarBind getVarBind(AgentXEntry entry, long column)
    {
        AgentXOID oid = new AgentXOID(getOID(), column, entry.getInstance());

        switch ((int)column) {
        case 2: // usrHistoryObjectVariable
        {
            AgentXOID value = ((UsrHistoryObjectEntry)entry).get_usrHistoryObjectVariable();
            return new AgentXVarBind(oid, AgentXVarBind.OBJECTIDENTIFIER, value);
        }
        case 3: // usrHistoryObjectSampleType
        {
            int value = ((UsrHistoryObjectEntry)entry).get_usrHistoryObjectSampleType();
            return new AgentXVarBind(oid, AgentXVarBind.INTEGER, value);
        }
        }

        return null;
    }

    public int setEntry(AgentXSetPhase phase,
                        AgentXEntry entry,
                        long column,
                        AgentXVarBind vb)
    {

        switch ((int)column) {
        case 2: // usrHistoryObjectVariable
        {
            if (vb.getType() != AgentXVarBind.OBJECTIDENTIFIER)
                return AgentXResponsePDU.WRONG_TYPE;
            else
                return ((UsrHistoryObjectEntry)entry).set_usrHistoryObjectVariable(phase, vb.AgentXOIDValue());
        }
        case 3: // usrHistoryObjectSampleType
        {
            if (vb.getType() != AgentXVarBind.INTEGER)
                return AgentXResponsePDU.WRONG_TYPE;
            else
                return ((UsrHistoryObjectEntry)entry).set_usrHistoryObjectSampleType(phase, vb.intValue());
        }
        }

        return AgentXResponsePDU.NOT_WRITABLE;
    }

}

