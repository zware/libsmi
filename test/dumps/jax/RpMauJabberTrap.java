/*
 * This Java file has been generated by smidump 0.2.13. Do not edit!
 * It is intended to be used within a Java AgentX sub-agent environment.
 *
 * $Id$
 */

import jax.AgentXOID;
import jax.AgentXVarBind;
import jax.AgentXNotification;
import java.util.Vector;

public class RpMauJabberTrap extends AgentXNotification
{

    private final static long[] rpMauJabberTrap_OID = {1, 3, 6, 1, 2, 1, 26, 0, 1};
    private static AgentXVarBind snmpTrapOID_VarBind =
        new AgentXVarBind(snmpTrapOID_OID,
                          AgentXVarBind.OBJECTIDENTIFIER,
                          new AgentXOID(rpMauJabberTrap_OID));

    private final static long[] OID1 = {1, 3, 6, 1, 2, 1, 26, 1, 1, 1, 8};
    private final static AgentXOID rpMauJabberState_OID = new AgentXOID(OID1);


    public RpMauJabberTrap(RpMauEntry rpMauEntry) {
        AgentXOID oid;
        AgentXVarBind varBind;

        // add the snmpTrapOID object
        varBindList.addElement(snmpTrapOID_VarBind);

        // add the rpMauJabberState columnar object
        oid = rpMauJabberState_OID;
        oid.appendImplied(rpMauEntry.getInstance());
        varBind = new AgentXVarBind(oid,
                                    AgentXVarBind.INTEGER,
                                    rpMauEntry.get_rpMauJabberState());
        varBindList.addElement(varBind);
    }

    public Vector getVarBindList() {
        return varBindList;
    }

}

