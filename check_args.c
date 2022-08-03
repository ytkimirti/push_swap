#include "push_swap.h"
#include "libft.h"

// Takes a string and check if that thing is
// an integer.
static bool is_integer(const char *str)
{
	int		    sign;
	long long	nb;
	int		    i;

	i = 0;
	nb = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb > 2147483647 && sign == 1)
			return false;
		if (nb > 2147483648 && sign == -1)
			return false;
		i++;
	}
	return (true);
}

// Returns the length of all of the nums
// Exits when sees that something is wrong with the arguments
int check_args(int argc, const char *argv[])
{
	int i;
	int j;
	int num_count;
	char **nums_str;

	if (argc <= 1)
		exit(0);
	i = 0;
	num_count = 0;
	while (i < argc)
	{
		nums_str = ft_split(argv[i], ' ');
		if (nums_str == NULL)
			exit_program();
		j = 0;
		while (nums_str && nums_str[j])
		{
			if (!is_integer(nums_str[j]))
				exit_program();
			num_count++;
			j++;
		}
		free(nums_str);
		i++;
	}
	if (num_count <= 1)
		exit_program();
	return num_count;
}
