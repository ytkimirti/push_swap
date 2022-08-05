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

Test(mixed_extract, no_rotate)
{
	int stack_len = 4;
	const int stack[] = {1, 2, 3, 4};

	int extract_count = 2;
	int rotate_count = 0;
	const int correct[] = {1, 2};

	int *result = extract_mixed_array(stack, extract_count, stack_len, rotate_count);

	struct cr_mem correct_mem = { .data = correct, .size = extract_count * sizeof (int) };
	struct cr_mem result_mem = { .data = result, .size = extract_count * sizeof (int) };

	cr_expect(eq(mem, correct_mem, result_mem));
}

Test(mixed_extract, more_rotate)
{
	int stack_len = 6;
	const int stack[] = {3, 4, 5, 6, 1, 2};

	int extract_count = 2;
	int rotate_count = 2;
 	int correct[] = {1, 2};

	int *result = extract_mixed_array(stack, extract_count, stack_len, rotate_count);

	cr_expect(eq(int[extract_count], result, correct));
}

Test(mixed_extract, rotate2)
{
	int stack_len = 6;
	const int stack[] = {3, 4, 5, 6, 1, 2};

	int extract_count = 4;
	int rotate_count = 2;
 	int correct[] = {1, 2, 3, 4};

	int *result = extract_mixed_array(stack, extract_count, stack_len, rotate_count);

	cr_expect(eq(int[extract_count], result, correct));
}

Test(mixed_extract, rotate3)
{
	int stack_len = 6;
	const int stack[] = {3, 4, 5, 6, 1, 2};

	int extract_count = 6;
	int rotate_count = 2;
 	int correct[] = {1, 2, 3, 4, 5, 6};

	int *result = extract_mixed_array(stack, extract_count, stack_len, rotate_count);

	cr_expect(eq(int[extract_count], result, correct));
}
