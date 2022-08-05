#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include "../src/utils.h"

Test(middle, small)
{
	int len = 1;
	const int nums[] = {1};

	cr_expect(eq(int, find_middle(nums, len), 1));
}

Test(middle, big)
{
	int len = 4;
	const int nums[] = {8, 1, 1239, 4};

	cr_expect(eq(int, find_middle(nums, len), 8));
}
Test(middle, middle)
{
	int len = 4;
	const int nums[] = {1, 2, 3, 4};

	cr_expect(eq(int, find_middle(nums, len), 3));
}
Test(middle, middle2)
{
	int len = 3;
	const int nums[] = {2, 3, 4};

	cr_expect(eq(int, find_middle(nums, len), 3));
}
