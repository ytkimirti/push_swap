#include "bubble_sort.h"
#include "parse_args.h"
#include "funcs.h"
#include "midwheel_algo.h"
#include "vars.h"
#include "../libft/libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "render.h"

void init(t_vars *vars, t_ivec *nums)
{
	int	i;

	vars->a = (t_stack *)malloc(sizeof(t_stack));
	vars->b = (t_stack *)malloc(sizeof(t_stack));
	if (!vars->a || !vars->b)
		exit_program();
	vars->a->nums = (int *)malloc(sizeof(int) * nums->len);
	vars->b->nums = (int *)malloc(sizeof(int) * nums->len);
	if (!vars->a->nums || !vars->b->nums)
		exit_program();
	vars->a->len = nums->len;
	vars->a->c = 'a';
	vars->b->len = 0;
	vars->b->c = 'b';
	vars->chunks = NULL;
	vars->print_next_command = true;
	i = 0;
	while (i < nums->len)
	{
		vars->a->nums[i] = nums->arr[i];
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
	t_ivec	*parsed_args;

	parsed_args = parse_args(argc, argv);
	init(&vars, parsed_args);
	ivec_del(parsed_args);
	midwheel_algo(&vars);
}
