/*
 * This Java file has been generated by smidump 0.2.13. It
 * is intended to be edited by the application programmer and
 * to be used within a Java AgentX sub-agent environment.
 *
 * $Id$
 */

/**
    This class extends the Java AgentX (JAX) implementation of
    the table row channel2Entry defined in RMON2-MIB.
 */

import jax.AgentXOID;
import jax.AgentXSetPhase;
import jax.AgentXResponsePDU;
import jax.AgentXEntry;

public class Channel2EntryImpl extends Channel2Entry
{

    // constructor
    public Channel2EntryImpl()
    {
        super();
    }

    public long get_channelDroppedFrames()
    {
        return channelDroppedFrames;
    }

    public long get_channelCreateTime()
    {
        return channelCreateTime;
    }

}

