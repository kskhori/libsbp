/* Copyright (C) 2015-2022 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.system;

// This file was auto-generated from yaml/swiftnav/sbp/system.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import java.math.BigInteger;
import org.json.JSONObject;

/**
 * SBP class for message MSG_PPS_TIME (0xFF08).
 *
 * <p>You can have MSG_PPS_TIME inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>The PPS time message contains the value of the sender's local time in microseconds at the
 * moment a pulse is detected on the PPS input. This is to be used for syncronisation of sensor data
 * sampled with a local timestamp (e.g. IMU or wheeltick messages) where GNSS time is unknown to the
 * sender.
 *
 * <p>The local time used to timestamp the PPS pulse must be generated by the same clock which is
 * used to timestamp the IMU/wheel sensor data and should follow the same roll-over rules. A
 * separate MSG_PPS_TIME message should be sent for each source of sensor data which uses
 * PPS-relative timestamping. The sender ID for each of these MSG_PPS_TIME messages should match the
 * sender ID of the respective sensor data.
 */
public class MsgPpsTime extends SBPMessage {
    public static final int TYPE = 0xFF08;

    /** Local time in microseconds */
    public BigInteger time;

    /** Status flags */
    public int flags;

    public MsgPpsTime(int sender) {
        super(sender, TYPE);
    }

    public MsgPpsTime() {
        super(TYPE);
    }

    public MsgPpsTime(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        time = parser.getU64();
        flags = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU64(time);
        builder.putU8(flags);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("time", time);
        obj.put("flags", flags);
        return obj;
    }
}