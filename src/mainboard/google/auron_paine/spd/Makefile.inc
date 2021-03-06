##
## This file is part of the coreboot project.
##
## Copyright (C) 2014 Google Inc.
## Copyright (C) 2015 CrowdStrike Inc. <georg@crowdstrike.com>
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; version 2 of the License.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##

romstage-y += spd.c

SPD_BIN = $(obj)/spd.bin

# { GPIO47, GPIO9, GPIO13 }
SPD_SOURCES  = Micron_4KTF25664HZ       # 0b0000
SPD_SOURCES += Hynix_HMT425S6AFR6A      # 0b0001
# ^ Hynix HMT425S6AFR6A-PBA
SPD_SOURCES += Hynix_HMT425S6CFR6A_H5TC4G63CFR  # 0b0010
# ^ Hynix HMT425S6CFR6A-PBA
SPD_SOURCES += Micron_4KTF25664HZ       # 0b0011
# ^ # Micron 4KTF25664HZ-1G6E1
SPD_SOURCES += Micron_4KTF25664HZ       # 0b0100
# ^ # Micron 4KTF25664HZ-1G6E1
SPD_SOURCES += Hynix_HMT425S6AFR6A      # 0b0101
SPD_SOURCES += Hynix_HMT425S6CFR6A_H5TC4G63CFR       # 0b0110
SPD_SOURCES += empty                    # 0b0111
SPD_SOURCES += empty                    # 0b1000
SPD_SOURCES += empty                    # 0b1001
SPD_SOURCES += empty                    # 0b1010
SPD_SOURCES += empty                    # 0b1011
SPD_SOURCES += empty                    # 0b1100
SPD_SOURCES += empty                    # 0b1101
SPD_SOURCES += empty                    # 0b1110
SPD_SOURCES += empty                    # 0b1111

SPD_DEPS := $(foreach f, $(SPD_SOURCES), src/mainboard/$(MAINBOARDDIR)/spd/$(f).spd.xxd)

# Include spd ROM data
$(SPD_BIN): $(SPD_DEPS)
	for f in $+; \
	  do xxd -rg1 $$f; \
	done > $@

cbfs-files-y += spd.bin
spd.bin-file := $(SPD_BIN)
spd.bin-type := 0xab
