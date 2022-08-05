#include "bubble_sort.h"
#include "check_args.h"
#include "funcs.h"
#include "midwheel_algo.h"
#include "vars.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

void init(t_vars *vars, const char *argv[], int argc, int len)
{
	int i;
	int j;
	int num_index;
	char **nums_str;

	vars->la = len;
	vars->lb = 0;
	vars->na = (int *)malloc(sizeof(int) * len);
	vars->nb = (int *)malloc(sizeof(int) * len);
	vars->print_next_command = true;
	num_index = 0;
	i = 1;
	while (i < argc)
	{
		nums_str = ft_split(argv[i], ' ');
		j = 0;
		while (nums_str[j])
		{
			vars->na[num_index] = ft_atoi(nums_str[j]);
			vars->nb[num_index] = -1;
			free(nums_str[j]);
			num_index++;
			j++;
		}
		free(nums_str);
		i++;
	}
}

void    test_funcs(t_vars *vars)
{
	rra(vars);
	rrb(vars);
	sa(vars);
	sb(vars);
	ss(vars);
	pa(vars);
	pb(vars);
	ra(vars);
	rb(vars);
	rr(vars);
	rrr(vars);
}

int	main(int argc, const char *argv[])
{
	t_vars	vars;
	int nums_len;

	nums_len = check_args(argc, argv);
	ft_printf("Nums len: %d\n", nums_len);
	init(&vars, argv, argc, nums_len);
	midwheel_algo(&vars);
}
