/*
 * This Java file has been generated by smidump 0.2.13. Do not edit!
 * It is intended to be used within a Java AgentX sub-agent environment.
 *
 * $Id$
 */

/**
    This class represents a Java AgentX (JAX) implementation of
    the table row addressMapEntry defined in RMON2-MIB.

    @version 1
    @author  smidump 0.2.13
    @see     AgentXTable, AgentXEntry
 */

import jax.AgentXOID;
import jax.AgentXSetPhase;
import jax.AgentXResponsePDU;
import jax.AgentXEntry;

public class AddressMapEntry extends AgentXEntry
{

    protected long addressMapTimeMark = 0;
    protected byte[] addressMapNetworkAddress = new byte[0];
    protected AgentXOID addressMapSource = new AgentXOID();
    protected byte[] addressMapPhysicalAddress = new byte[0];
    protected long addressMapLastChange = 0;
    // foreign indices
    protected int protocolDirLocalIndex;

    public AddressMapEntry(long addressMapTimeMark,
                           int protocolDirLocalIndex,
                           byte[] addressMapNetworkAddress,
                           AgentXOID addressMapSource)
    {
        this.addressMapTimeMark = addressMapTimeMark;
        this.protocolDirLocalIndex = protocolDirLocalIndex;
        this.addressMapNetworkAddress = addressMapNetworkAddress;
        this.addressMapSource = addressMapSource;

        instance.append(addressMapTimeMark);
        instance.append(protocolDirLocalIndex);
        instance.append(addressMapNetworkAddress);
        instance.append(addressMapSource);
    }

    public long get_addressMapTimeMark()
    {
        return addressMapTimeMark;
    }

    public int get_protocolDirLocalIndex()
    {
        return protocolDirLocalIndex;
    }

    public byte[] get_addressMapNetworkAddress()
    {
        return addressMapNetworkAddress;
    }

    public AgentXOID get_addressMapSource()
    {
        return addressMapSource;
    }

    public byte[] get_addressMapPhysicalAddress()
    {
        return addressMapPhysicalAddress;
    }

    public long get_addressMapLastChange()
    {
        return addressMapLastChange;
    }

}

