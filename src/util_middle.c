#include "bubble_sort.h"
#include <stdbool.h>
#include <stdlib.h>

int *copy_array(int *nums, int len)
{
	int	*new_arr;
	int	i;

	new_arr = (int *)malloc(sizeof(int) * len);

	i = 0;
	while (i < len)
	{
		new_arr[i] = nums[i];
		i++;
	}
	return new_arr;
}

int find_middle(int *nums, int len)
{
	int *sorted;
	int	middle;

	sorted = copy_array(nums, len);
	bubble_sort(sorted, len);
	middle = sorted[len / 2];
	free(sorted);
	return (middle);
}

bool is_sorted(int *nums, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (nums[i] >= nums[i + 1])
			return (false);
		i++;
	}
	return (true);
}

int	*extract_mixed_array(const int *nums, int len, int stack_len, int rotate_count)
{
	int	*result;
	int	i;

	result = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (i < rotate_count)
	{
		result[i] = nums[stack_len - rotate_count + i];
		len--;
		i++;
	}
	i = 0;
	while (i < len)
	{
		result[rotate_count + i] = nums[i];
		i++;
	}
	return (result);
}
