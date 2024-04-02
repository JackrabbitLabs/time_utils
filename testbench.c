/* SPDX-License-Identifier: Apache-2.0 */
/**
 * @file 		testbench.c
 *
 * @brief 		Testbench code file for Time Utils library
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

#include "timeutils.h"

/* MACROS ====================================================================*/

/* ENUMERATIONS ==============================================================*/

/* STRUCTS ===================================================================*/

/* GLOBAL VARIABLES ==========================================================*/

/* PROTOTYPES ================================================================*/

/* FUNCTIONS =================================================================*/

int main()
{
	struct timespec a, b, c;
	int rv;

	printf("Add two time specs-------------------\n");
	timespec_set(&a, 10, 17);
	timespec_set(&b, 23, 11);
	timespec_add(&a, &b, &c);
	timespec_print(&a);
	timespec_print(&b);
	timespec_print(&c);

	printf("\nAdd two time specs-------------------\n");
	timespec_set(&a, -10, 17);
	timespec_set(&b, 23, -11);
	timespec_add(&a, &b, &c);
	timespec_print(&a);
	timespec_print(&b);
	timespec_print(&c);

	printf("\nAdd two time specs-------------------\n");
	timespec_set(&a, -10, -17);
	timespec_set(&b, 23, -11);
	timespec_add(&a, &b, &c);
	timespec_print(&a);
	timespec_print(&b);
	timespec_print(&c);

	printf("\nAdd two time specs-------------------\n");
	timespec_set(&a, 10, 999999999);
	timespec_set(&b, 23, 11);
	timespec_add(&a, &b, &c);
	timespec_print(&a);
	timespec_print(&b);
	timespec_print(&c);

	printf("\nAdd two time specs-------------------\n");
	timespec_set(&a, 10, 1000000001);
	timespec_set(&b, 23, 1000000001);
	timespec_add(&a, &b, &c);
	timespec_print(&a);
	timespec_print(&b);
	timespec_print(&c);

	printf("\nAdd two time specs-------------------\n");
	timespec_set(&a, 10, -1000000001);
	timespec_set(&b, 23, -1000000001);
	timespec_add(&a, &b, &c);
	timespec_print(&a);
	timespec_print(&b);
	timespec_print(&c);

	printf("\nAdd two time specs-------------------\n");
	timespec_set(&a, 10, 4000000001);
	timespec_set(&b, 23, 4000000001);
	timespec_add(&a, &b, &c);
	timespec_print(&a);
	timespec_print(&b);
	timespec_print(&c);

	printf("\ncmp two time specs-------------------\n");
	timespec_set(&a, 10, 1);
	timespec_set(&b, 10, 1);
	rv = timespec_cmp(&a, &b);
	timespec_print(&a);
	timespec_print(&b);
	printf("rv = %d\n", rv);

	printf("\ncmp two time specs-------------------\n");
	timespec_set(&a, 10, 1);
	timespec_set(&b, 11, 1);
	rv = timespec_cmp(&a, &b);
	timespec_print(&a);
	timespec_print(&b);
	printf("rv = %d\n", rv);

	printf("\ncmp two time specs-------------------\n");
	timespec_set(&a, 11, 1);
	timespec_set(&b, 10, 1);
	rv = timespec_cmp(&a, &b);
	timespec_print(&a);
	timespec_print(&b);
	printf("rv = %d\n", rv);

	printf("\ncmp two time specs-------------------\n");
	timespec_set(&a, 10, 1);
	timespec_set(&b, 10, 2);
	rv = timespec_cmp(&a, &b);
	timespec_print(&a);
	timespec_print(&b);
	printf("rv = %d\n", rv);

	printf("\ncmp two time specs-------------------\n");
	timespec_set(&a, 10, 2);
	timespec_set(&b, 10, 1);
	rv = timespec_cmp(&a, &b);
	timespec_print(&a);
	timespec_print(&b);
	printf("rv = %d\n", rv);

	printf("\ncmp two time specs-------------------\n");
	timespec_set(&a, 11, 1);
	timespec_set(&b, 10, 1000000002);
	rv = timespec_cmp(&a, &b);
	timespec_print(&a);
	timespec_print(&b);
	printf("rv = %d\n", rv);

	printf("\nDiff two time specs-------------------\n");
	timespec_set(&a, 23, 1);
	timespec_set(&b, 10, 1);
	timespec_diff(&a, &b, &c);
	timespec_print(&a);
	timespec_print(&b);
	timespec_print(&c);

	printf("\nDiff two time specs-------------------\n");
	timespec_set(&a, 23, 1);
	//timespec_set(&b, 10, 1000000001);
	b.tv_sec = 10; b.tv_nsec = 1000000001;
	timespec_diff(&a, &b, &c);
	timespec_print(&a);
	timespec_print(&b);
	timespec_print(&c);

	printf("\nDiff two time specs-------------------\n");
	//timespec_set(&a, 23, 1);
	a.tv_sec = 23; a.tv_nsec = 2000000001;
	//timespec_set(&b, 10, 1000000001);
	b.tv_sec = 10; b.tv_nsec = 1000000001;
	timespec_diff(&a, &b, &c);
	timespec_print(&a);
	timespec_print(&b);
	timespec_print(&c);

	printf("\nDiff two time specs-------------------\n");
	timespec_set(&a, 0, 0);
	//timespec_set(&b, 10, 1000000001);
	b.tv_sec = 10; b.tv_nsec = 1000000001;
	timespec_diff(&a, &b, &c);
	timespec_print(&a);
	timespec_print(&b);
	timespec_print(&c);

	printf("\nDiff two time specs-------------------\n");
	timespec_set(&a, 0, 0);
	//timespec_set(&b, 10, 1000000001);
	b.tv_sec = 10; b.tv_nsec = 2000000001;
	timespec_diff(&a, &b, &c);
	timespec_print(&a);
	timespec_print(&b);
	timespec_print(&c);

	printf("\nDiff two time specs-------------------\n");
	timespec_set(&a, -1, 0);
	timespec_set(&b, -10, 2000000001);
	//b.tv_sec = -10; b.tv_nsec = 2000000001;
	timespec_diff(&a, &b, &c);
	timespec_print(&a);
	timespec_print(&b);
	timespec_print(&c);

	printf("\nDiff two time specs-------------------\n");
	timespec_set(&a, -1, 0);
	timespec_set(&b, -10, -2000000001);
	//b.tv_sec = -10; b.tv_nsec = 2000000001;
	timespec_diff(&a, &b, &c);
	timespec_print(&a);
	timespec_print(&b);
	timespec_print(&c);

	printf("\nCompare two time specs-------------------\n");
	clock_gettime(CLOCK_MONOTONIC, &a);
	clock_gettime(CLOCK_MONOTONIC, &b);
	printf("timespec_cmp(a,b): %d\n", timespec_cmp(&a,&b));
	printf("timespec_cmp(b,a): %d\n", timespec_cmp(&b,&a));
	printf("timespec_cmp(a,a): %d\n", timespec_cmp(&a,&a));

	printf("\nTest if time has elapsed ----------------\n");
	clock_gettime(CLOCK_MONOTONIC, &a);
	a.tv_sec += 5;
	printf("timespec_elapsed(a): %d\n", timespec_elapsed(&a,-1));

	printf("\nTest if time has elapsed ----------------\n");
	clock_gettime(CLOCK_MONOTONIC, &a);
	a.tv_sec -= 5;
	printf("timespec_elapsed(a): %d\n", timespec_elapsed(&a,-1));

	return 0;
}
