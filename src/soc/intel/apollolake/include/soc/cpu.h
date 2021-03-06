/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2015 Intel Corp.
 * (Written by Alexandru Gagniuc <alexandrux.gagniuc@intel.com> for Intel Corp.)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _SOC_APOLLOLAKE_CPU_H_
#define _SOC_APOLLOLAKE_CPU_H_

#ifndef __ASSEMBLER__
#include <cpu/x86/msr.h>
#include <device/device.h>

void apollolake_init_cpus(struct device *dev);
#endif

#define CPUID_APOLLOLAKE_A0	0x506c8
#define CPUID_APOLLOLAKE_B0	0x506c9

#define MSR_PLATFORM_INFO	0xce
#define MSR_POWER_MISC		0x120
#define MSR_CORE_THREAD_COUNT	0x35
#define MSR_EVICT_CTL		0x2e0
#define MSR_EMULATE_PM_TMR	0x121
#define   EMULATE_PM_TMR_EN	(1 << 16)
#define MSR_PREFETCH_CTL	0x1a4
#define   PREFETCH_L1_DISABLE	(1 << 0)
#define   PREFETCH_L2_DISABLE	(1 << 2)


#define MSR_L2_QOS_MASK(reg)		(0xd10 + reg)
#define MSR_IA32_PQR_ASSOC		0xc8f
/* MSR bits 33:32 encode slot number 0-3 */
#define   IA32_PQR_ASSOC_MASK		(1 << 0 | 1 << 1)
/* 16 way cache, 8 bits per QOS, 64 byte cache line, 1024 sets */
#define CACHE_WAYS			16
#define CACHE_BITS_PER_MASK		8
#define CACHE_LINE_SIZE			64
#define CACHE_SETS			1024
/*
 * Each bit in QOS mask controls this many bytes. This is calculated as:
 * (CACHE_WAYS / CACHE_BITS_PER_MASK) * CACHE_LINE_SIZE * CACHE_SETS
 */
#define CACHE_QOS_SIZE_PER_BIT		(128 * KiB)
#define L2_CACHE_SIZE			0x100000

#define BASE_CLOCK_MHZ		100

/* Common Timer Copy (CTC) frequency - 19.2MHz. */
#define CTC_FREQ 19200000

#endif /* _SOC_APOLLOLAKE_CPU_H_ */
