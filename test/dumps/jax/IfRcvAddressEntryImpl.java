/*
 * This Java file has been generated by smidump 0.2.8. It
 * is intended to be edited by the application programmer and
 * to be used within a Java AgentX sub-agent environment.
 *
 * $Id$
 */

/**
    This class extends the Java AgentX (JAX) implementation of
    the table row ifRcvAddressEntry defined in IF-MIB.
 */

import jax.AgentXOID;
import jax.AgentXSetPhase;
import jax.AgentXResponsePDU;
import jax.AgentXEntry;

public class IfRcvAddressEntryImpl extends IfRcvAddressEntry
{

    // constructor
    public IfRcvAddressEntryImpl(int ifIndex,
                             byte[] ifRcvAddressAddress)
    {
        super(ifIndex,
                   ifRcvAddressAddress);
    }

    public int get_ifRcvAddressStatus()
    {
        return ifRcvAddressStatus;
    }

    public int set_ifRcvAddressStatus(AgentXSetPhase phase, int value)
    {
        switch (phase.getPhase()) {
        case AgentXSetPhase.TEST_SET:
            break;
        case AgentXSetPhase.COMMIT:
            undo_ifRcvAddressStatus = ifRcvAddressStatus;
            ifRcvAddressStatus = value;
            break;
        case AgentXSetPhase.UNDO:
            ifRcvAddressStatus = undo_ifRcvAddressStatus;
            break;
        case AgentXSetPhase.CLEANUP:
            break;
        default:
            return AgentXResponsePDU.PROCESSING_ERROR;
        }
        return AgentXResponsePDU.NO_ERROR;
    }
    public int get_ifRcvAddressType()
    {
        return ifRcvAddressType;
    }

    public int set_ifRcvAddressType(AgentXSetPhase phase, int value)
    {
        switch (phase.getPhase()) {
        case AgentXSetPhase.TEST_SET:
            break;
        case AgentXSetPhase.COMMIT:
            undo_ifRcvAddressType = ifRcvAddressType;
            ifRcvAddressType = value;
            break;
        case AgentXSetPhase.UNDO:
            ifRcvAddressType = undo_ifRcvAddressType;
            break;
        case AgentXSetPhase.CLEANUP:
            break;
        default:
            return AgentXResponsePDU.PROCESSING_ERROR;
        }
        return AgentXResponsePDU.NO_ERROR;
    }
}

