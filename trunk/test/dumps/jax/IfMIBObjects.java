/*
 * This Java file has been generated by smidump 0.2.11. Do not edit!
 * It is intended to be used within a Java AgentX sub-agent environment.
 *
 * $Id$
 */

/**
    This class represents a Java AgentX (JAX) implementation of
    the scalar group ifMIBObjects defined in IF-MIB.

    @version 1
    @author  smidump 0.2.11
    @see     AgentXGroup, AgentXScalars
 */

import java.util.Vector;
import java.util.Enumeration;
import jax.AgentXOID;
import jax.AgentXVarBind;
import jax.AgentXSetPhase;
import jax.AgentXResponsePDU;
import jax.AgentXScalars;

public class IfMIBObjects extends AgentXScalars
{

    private final static long[] IfMIBObjectsOID = {1, 3, 6, 1, 2, 1, 31, 1};

    protected AgentXOID IfTableLastChangeOID;
    protected final static long[] IfTableLastChangeName = {1, 3, 6, 1, 2, 1, 31, 1, 5, 0};
    protected long ifTableLastChange = 0;
    protected AgentXOID IfStackLastChangeOID;
    protected final static long[] IfStackLastChangeName = {1, 3, 6, 1, 2, 1, 31, 1, 6, 0};
    protected long ifStackLastChange = 0;
    public IfMIBObjects()
    {
        oid = new AgentXOID(IfMIBObjectsOID);
        data = new Vector();
        IfTableLastChangeOID = new AgentXOID(IfTableLastChangeName);
        data.addElement(IfTableLastChangeOID);
        IfStackLastChangeOID = new AgentXOID(IfStackLastChangeName);
        data.addElement(IfStackLastChangeOID);
    }

    public long get_ifTableLastChange()
    {
        return ifTableLastChange;
    }

    public long get_ifStackLastChange()
    {
        return ifStackLastChange;
    }

    public AgentXVarBind getScalar(AgentXOID pos, AgentXOID oid)
    {
        if ((pos == null) || (pos.compareTo(oid) != 0))
            return new AgentXVarBind(oid, AgentXVarBind.NOSUCHOBJECT);
        else {
            if (pos == IfTableLastChangeOID)
                return new AgentXVarBind(oid, AgentXVarBind.TIMETICKS, 
                                         get_ifTableLastChange());
            if (pos == IfStackLastChangeOID)
                return new AgentXVarBind(oid, AgentXVarBind.TIMETICKS, 
                                         get_ifStackLastChange());
        }
        return new AgentXVarBind(oid, AgentXVarBind.NOSUCHOBJECT);
    }

    public int setScalar(AgentXSetPhase phase, AgentXOID pos,
                         AgentXVarBind inVb)
    {
        if ((pos == null) || (pos.compareTo(inVb.getOID()) != 0))
            return AgentXResponsePDU.INCONSISTENT_NAME;
        else {
        }
        return AgentXResponsePDU.NOT_WRITABLE;
    }

    public AgentXVarBind getNextScalar(AgentXOID pos, AgentXOID oid)
    {
        if ((pos == null) || (pos.compareTo(oid) <= 0))
            return new AgentXVarBind(oid, AgentXVarBind.ENDOFMIBVIEW);
        else {
            if (pos == IfTableLastChangeOID)
                return new AgentXVarBind(pos, AgentXVarBind.TIMETICKS, 
                                         get_ifTableLastChange());
            if (pos == IfStackLastChangeOID)
                return new AgentXVarBind(pos, AgentXVarBind.TIMETICKS, 
                                         get_ifStackLastChange());
        }
        return new AgentXVarBind(pos, AgentXVarBind.ENDOFMIBVIEW);
    }

}

