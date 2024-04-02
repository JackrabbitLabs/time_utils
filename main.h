/* SPDX-License-Identifier: Apache-2.0 */
/**
 * @file 		timeutils.h
 *
 * @brief 		Header file for Time Utils Library 
 *
 * @copyright 	Copyright (C) 2024 Jackrabbit Founders LLC. All rights reserved.
 *
 * @date 		Mar 2024
 * @author 		Barrett Edwards <code@jrlabs.io>
 * 
 * Macro / Enumeration Prefixes 
 */

#ifndef _TIMEUTILS_H
#define _TIMEUTILS_H

/* INCLUDES ==================================================================*/

#include <linux/types.h>

/* MACROS ====================================================================*/

/* ENUMERATIONS ==============================================================*/

/* STRUCTS ===================================================================*/

/* GLOBAL VARIABLES ==========================================================*/

/* PROTOTYPES ================================================================*/

char *isotime(char *buf, int len);
void timespec_add(struct timespec *a, struct timespec *b, struct timespec *result);
void timespec_copy(struct timespec *dst, struct timespec *src);
int timespec_cmp(struct timespec *lhs, struct timespec *rhs);
void timespec_diff(struct timespec *a, struct timespec *b, struct timespec *result);
int timespec_elapsed(struct timespec* t, clockid_t cid);
void timespec_norm(struct timespec *t);
void timespec_print(struct timespec *t);
void timespec_set(struct timespec *t, time_t sec, long nsec);

/* INLINE FUNCTIONS ==========================================================*/

#endif //ifndef _TIMEUTILS_H
