/*
 * This Java file has been generated by smidump 0.2.13. Do not edit!
 * It is intended to be used within a Java AgentX sub-agent environment.
 *
 * $Id$
 */

/**
    This class represents a Java AgentX (JAX) implementation of
    the table ifRcvAddressTable defined in IF-MIB.

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

public class IfRcvAddressTable extends AgentXTable
{

    // entry OID
    private final static long[] OID = {1, 3, 6, 1, 2, 1, 31, 1, 4, 1};

    // constructors
    public IfRcvAddressTable()
    {
        oid = new AgentXOID(OID);

        // register implemented columns
        columns.addElement(new Long(2));
        columns.addElement(new Long(3));
    }

    public IfRcvAddressTable(boolean shared)
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
        case 2: // ifRcvAddressStatus
        {
            int value = ((IfRcvAddressEntry)entry).get_ifRcvAddressStatus();
            return new AgentXVarBind(oid, AgentXVarBind.INTEGER, value);
        }
        case 3: // ifRcvAddressType
        {
            int value = ((IfRcvAddressEntry)entry).get_ifRcvAddressType();
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
        case 2: // ifRcvAddressStatus
        {
            if (vb.getType() != AgentXVarBind.INTEGER)
                return AgentXResponsePDU.WRONG_TYPE;
            else
                return ((IfRcvAddressEntry)entry).set_ifRcvAddressStatus(phase, vb.intValue());
        }
        case 3: // ifRcvAddressType
        {
            if (vb.getType() != AgentXVarBind.INTEGER)
                return AgentXResponsePDU.WRONG_TYPE;
            else
                return ((IfRcvAddressEntry)entry).set_ifRcvAddressType(phase, vb.intValue());
        }
        }

        return AgentXResponsePDU.NOT_WRITABLE;
    }

}

