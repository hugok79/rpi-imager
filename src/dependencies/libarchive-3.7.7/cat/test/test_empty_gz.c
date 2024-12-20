/*-
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2014 Sebastian Freundt
 * All rights reserved.
 */
#include "test.h"

DEFINE_TEST(test_empty_gz)
{
	const char *reffile = "test_empty.gz";
	int f;

	extract_reference_file(reffile);
	f = systemf("%s %s >test.out 2>test.err", testprog, reffile);
	if (f == 0 || canGzip()) {
		assertEqualInt(0, f);
		assertEmptyFile("test.out");
		assertEmptyFile("test.err");
	} else {
		skipping("It seems gzip is not supported on this platform");
	}
}
