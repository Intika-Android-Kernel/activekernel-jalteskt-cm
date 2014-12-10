/*
 * include/linux/exynos_ion.h
 *
 * Copyright (C) 2011 Google, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef _LINUX_EXYNOS_ION_H
#define _LINUX_EXYNOS_ION_H

#include <linux/ion.h>

enum {
	ION_HEAP_TYPE_EXYNOS_CONTIG = ION_HEAP_TYPE_CUSTOM + 1,
	ION_HEAP_TYPE_EXYNOS,
	ION_HEAP_TYPE_EXYNOS_USER,
};

#define ION_HEAP_EXYNOS_CONTIG_MASK	(1 << ION_HEAP_TYPE_EXYNOS_CONTIG)
#define ION_HEAP_EXYNOS_MASK		(1 << ION_HEAP_TYPE_EXYNOS)
#define ION_HEAP_EXYNOS_USER_MASK	(1 << ION_HEAP_TYPE_EXYNOS_USER)

enum {
	ION_EXYNOS_ID_COMMON		= 0,
	ION_EXYNOS_ID_MFC_SH		= 2,
	ION_EXYNOS_ID_G2D_WFD		= 3,
	ION_EXYNOS_ID_FIMD_VIDEO	= 4,
	ION_EXYNOS_ID_GSC		= 5,
	ION_EXYNOS_ID_MFC_OUTPUT	= 6,
	ION_EXYNOS_ID_MFC_INPUT		= 7,
	ION_EXYNOS_ID_MFC_FW		= 8,
	ION_EXYNOS_ID_SECTBL		= 9,
	ION_EXYNOS_MAX_CONTIG_ID
};

/* reserved 2 bits between contig heap masks and write mask */
#define ION_EXYNOS_WRITE_MASK		\
	(1 << (BITS_PER_LONG - ION_EXYNOS_MAX_CONTIG_ID - 2))

#define MAKE_CONTIG_MASK(id)		(1 << (BITS_PER_LONG - id))
#define ION_EXYNOS_CONTIG_ID_MASK	\
	~(MAKE_CONTIG_MASK(ION_EXYNOS_MAX_CONTIG_ID) - 1)

#define ION_EXYNOS_MFC_SH_MASK		MAKE_CONTIG_MASK(ION_EXYNOS_ID_MFC_SH)
#define ION_EXYNOS_G2D_WFD_MASK		MAKE_CONTIG_MASK(ION_EXYNOS_ID_G2D_WFD)
#define ION_EXYNOS_FIMD_VIDEO_MASK    MAKE_CONTIG_MASK(ION_EXYNOS_ID_FIMD_VIDEO)
#define ION_EXYNOS_GSC_MASK		MAKE_CONTIG_MASK(ION_EXYNOS_ID_GSC)
#define ION_EXYNOS_MFC_OUTPUT_MASK    MAKE_CONTIG_MASK(ION_EXYNOS_ID_MFC_OUTPUT)
#define ION_EXYNOS_MFC_INPUT_MASK     MAKE_CONTIG_MASK(ION_EXYNOS_ID_MFC_INPUT)
#define ION_EXYNOS_MFC_FW_MASK		MAKE_CONTIG_MASK(ION_EXYNOS_ID_MFC_FW)
#define ION_EXYNOS_SECTBL_MASK		MAKE_CONTIG_MASK(ION_EXYNOS_ID_SECTBL)

#define ION_HEAP_EXYNOS_MFC_SH_MASK					\
		(ION_HEAP_EXYNOS_CONTIG_MASK|ION_EXYNOS_MFC_SH_MASK)
#define ION_HEAP_EXYNOS_MFC_FW_MASK					\
		(ION_HEAP_EXYNOS_CONTIG_MASK|ION_EXYNOS_MFC_FW_MASK)
#define ION_HEAP_EXYNOS_SECTBL_MASK					\
		(ION_HEAP_EXYNOS_CONTIG_MASK|ION_EXYNOS_SECTBL_MASK)
#define ION_HEAP_EXYNOS_FIMD_VIDEO_MASK					\
		(ION_HEAP_EXYNOS_CONTIG_MASK|ION_EXYNOS_FIMD_VIDEO_MASK)
#define ION_HEAP_EXYNOS_GSC_MASK					\
		(ION_HEAP_EXYNOS_CONTIG_MASK|ION_EXYNOS_GSC_MASK)
#define ION_HEAP_EXYNOS_MFC_OUTPUT_MASK					\
		(ION_HEAP_EXYNOS_CONTIG_MASK|ION_EXYNOS_MFC_OUTPUT_MASK)
#define ION_HEAP_EXYNOS_MFC_INPUT_MASK					\
		(ION_HEAP_EXYNOS_CONTIG_MASK|ION_EXYNOS_MFC_INPUT_MASK)
#define ION_HEAP_EXYNOS_G2D_WFD_MASK					\
		(ION_HEAP_EXYNOS_CONTIG_MASK|ION_EXYNOS_G2D_WFD_MASK)

#endif /* _LINUX_ION_H */
