#include "bubble_sort.h"
#include "check_args.h"
#include "funcs.h"
#include "midwheel_algo.h"
#include "vars.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void init(t_vars *vars, const char *argv[], int argc, int len)
{
	int i;
	int j;
	int num_index;
	char **nums_str;

	vars->a = (t_stack *)malloc(sizeof(t_stack));
	vars->a->len = len;
	vars->a->nums = (int *)malloc(sizeof(int) * len);
	vars->a->c = 'a';

	vars->b = (t_stack *)malloc(sizeof(t_stack));
	vars->b->len = 0;
	vars->b->nums = (int *)malloc(sizeof(int) * len);
	vars->b->c = 'b';

	vars->chunks = NULL;
	vars->print_next_command = true;
	num_index = 0;
	i = 1;
	while (i < argc)
	{
		nums_str = ft_split(argv[i], ' ');
		j = 0;
		while (nums_str[j])
		{
			vars->a->nums[num_index] = ft_atoi(nums_str[j]);
			vars->b->nums[num_index] = -1;
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
	t_stack *a;
	t_stack *b;

	a = vars->a;
	b = vars->b;

	px(vars, a, b);
	px(vars, a, b);
	px(vars, a, b);

	rx(vars, a);
	rx(vars, b);

	rrx(vars, a);
	rrx(vars, b);

	sx(vars, a);
	sx(vars, b);
	ss(vars);

	px(vars, b, a);
	px(vars, b, a);

	px(vars, a, b);
	px(vars, a, b);

	rr(vars);
	rrr(vars);
}

int	main(int argc, const char *argv[])
{
	t_vars	vars;
	int nums_len;

	nums_len = check_args(argc, argv);
	init(&vars, argv, argc, nums_len);

	//test_funcs(&vars);
	midwheel_algo(&vars);
}
