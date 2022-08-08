#include <stdbool.h>

bool is_sorted(const int *nums, int len)
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

bool is_sorted_descending(const int *nums, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (nums[i] <= nums[i + 1])
			return (false);
		i++;
	}
	return (true);
}

