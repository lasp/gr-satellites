#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Copyright 2018, 2019 Daniel Estevez <daniel@destevez.net>
# Copyright 2021 The Regents of the University of Colorado
#
# This file is part of gr-satellites
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

from datetime import datetime
from construct import Adapter, BitsInteger, BitStruct, Container, Flag, \
                      Int8ub, Int16ub, Int32ub, \
                      Padding, Struct, Switch
from .ax25 import Header
from .cute_bct_fsw import cute_bct_fsw
from .cute_bct_soh import cute_bct_soh

PrimaryHeader = BitStruct(
    'ccsds_version' / BitsInteger(3),
    'packet_type' / Flag,
    'secondary_header_flag' / Flag,
    'is_stored_data' / Flag,
    'APID' / BitsInteger(10),
    'grouping_flag' / BitsInteger(2),
    'sequence_count' / BitsInteger(14),
    'packet_length' / BitsInteger(16)
    )

class TimeAdapter(Adapter):
    def _encode(self, obj, context, path=None):
        return Container()

    def _decode(self, obj, context, path=None):
        offset = datetime(2000,1,1,12) - datetime(1970,1,1)
        return (datetime.utcfromtimestamp(obj.time_stamp_seconds) + offset)

SecondaryHeaderRaw = Struct(
    'time_stamp_seconds' / Int32ub,
    'sub_seconds' / Int8ub,
    Padding(1)
)

SecondaryHeader = TimeAdapter(
    SecondaryHeaderRaw
)

cute_70cm = Struct(
    'ax25_header' / Header,
    'primary_header' / PrimaryHeader,
    'secondary_header' / SecondaryHeader,
    'packet' / Switch(
        lambda c: (c.primary_header.APID),
        {
            (0x56): cute_bct_soh
        }
    )
)
