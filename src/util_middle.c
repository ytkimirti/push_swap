#include "bubble_sort.h"
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
