/* SPDX-License-Identifier: Apache-2.0 */
/**
 * @file 		timeutils.c
 *
 * @brief 		Code file for Time Utils library
 *
 * @copyright 	Copyright (C) 2024 Jackrabbit Founders LLC. All rights reserved.
 *
 * @date 		Mar 2024
 * @author 		Barrett Edwards <code@jrlabs.io>
 * 
 */

/* INCLUDES ==================================================================*/

/* printf()
 */
#include <stdio.h>

/* timespec 
 */
#include <time.h>

#include "main.h"

/* MACROS ====================================================================*/

/* ENUMERATIONS ==============================================================*/

/* STRUCTS ===================================================================*/

/* GLOBAL VARIABLES ==========================================================*/

/* PROTOTYPES ================================================================*/

/* FUNCTIONS =================================================================*/

/**
 * Obtiain and store current time in a string buffer in ISO format 
 *
 * @param buf	char* buffer to store ISO string representation of current time
 * @param len 	int length of buffer to not exceed
 * @return 		returns a pointer to buffer for convenience
 */
char *isotime(char *buf, int len)
{
	time_t t; 
	struct tm tm;

	// Gets the gurrent UTC time in seconds
	t = time(NULL); 	

	// Convert time into struct tm format 
	gmtime_r(&t, &tm);  

	// Store time in string buffer in ISO format 
	strftime(buf, len, "%F %T", &tm);	

	return buf;
}

/**
 * Add two timespec values
 *
 * @param a			struct timespec*
 * @param b			struct timespec*
 * @param result 	struct timespec*
 */
void timespec_add(struct timespec *a, struct timespec *b, struct timespec *result)
{
	result->tv_sec = a->tv_sec + b->tv_sec;
	result->tv_nsec = a->tv_nsec + b->tv_nsec;
	timespec_norm(result);
}

/**
 * Copy a timespec into another 
 *
 * @param dst	struct timespec*
 * @param src	struct timespec*
 */
void timespec_copy(struct timespec *dst, struct timespec *src)
{
	dst->tv_sec  = src->tv_sec;
	dst->tv_nsec = src->tv_nsec;
}

/**
 * Compare timespec a and b. Return which is greater. 
 *
 * Behavior is undefined if lhs or rhs are not pointers to null-terminated byte strings. 
 *
 * @return  1 : lhs > rhs
 *          0 : lhs = rhs
 *         -1 : lhs < rhs
 */
int timespec_cmp(struct timespec *lhs, struct timespec *rhs)
{
	struct timespec A, B;
	int rv;

	rv = 0;

	// Copy into local varaibles and normalize as we cannot modify input parameters 
	timespec_set(&A, lhs->tv_sec, lhs->tv_nsec);
	timespec_set(&B, rhs->tv_sec, rhs->tv_nsec);

	if (A.tv_sec > B.tv_sec)
		rv = 1;
	else if (A.tv_sec < B.tv_sec)
		rv = -1;
	else 
	{
		if (A.tv_nsec > B.tv_nsec)
			rv = 1;
		else if (A.tv_nsec < B.tv_nsec)
			rv = -1;
	}

	return rv;
}

/**
 * Compute difference between timespec a and b. Result = a - b
 *
 * Result will be normalized. Input parameters are not modified
 *
 * @param a			struct timespec* 
 * @param b 		struct timespec*
 * @param result	struct timespec*
 */
void timespec_diff(struct timespec *a, struct timespec *b, struct timespec *result)
{
	result->tv_sec = a->tv_sec - b->tv_sec;
	result->tv_nsec = a->tv_nsec - b->tv_nsec;
	timespec_norm(result);
}

/**
 * Tests if a time specified has elapsed 
 *
 * @param t 	struct timespec* the time to test
 * @param cid 	Clock ID to determine current time. If <0 use CLOCK_MONOTONIC 
 * @return 		1 if time has past, 0 if it has not
 */
int timespec_elapsed(struct timespec* t, clockid_t cid)
{
	struct timespec now;
	int rv;

	// Initialize variables 
	rv = 0; 
	if (cid < 0)
		cid = CLOCK_MONOTONIC;
	clock_gettime(cid, &now);

	// Compare provided time to now
	rv = timespec_cmp(&now, t);

	// bound rv to 0 or 1
	if (rv < 0)
		rv = 0;

	return rv;
}

/**
 * Normalize a timespec object to standard time form
 *
 * Rounds tv_nsec to be between 0 - 1B nano seconds

 * @param t 	struct timespec* to normalize
 */
void timespec_norm(struct timespec *t)
{
	if (t->tv_nsec >= 1000000000) 
	{
		t->tv_sec  += (t->tv_nsec / 1000000000);
		t->tv_nsec %= 1000000000;
	}
	else if (t->tv_nsec < 0)
	{
		t->tv_sec  -= ((t->tv_nsec / -1000000000) + 1);
		t->tv_nsec %= 1000000000;
		if (t->tv_nsec < 0)
			t->tv_nsec += 1000000000;
		else if (t->tv_nsec == 0)
			t->tv_sec += 1;
	}
}

/**
 * Print a timespec object 
 *
 * @param t 	struct timespec*
 */
void timespec_print(struct timespec *t)
{
	printf("timespec:  %ld:%ld\n", t->tv_sec, t->tv_nsec); 
}

/**
 * Fill and normalize a timespec object 
 *
 * @param t		struct timespec* to fill
 * @param sec 	time_t of seconds to set
 * @param nsec  long of nanoseconds to use 
 */
void timespec_set(struct timespec *t, time_t sec, long nsec)
{
	t->tv_sec = sec;
	t->tv_nsec = nsec;
	timespec_norm(t);
}


