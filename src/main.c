#include "push_swap.h"
#include "bubble_sort.h"
#include "funcs.h"

void init(t_vars *vars, const char *args[], int len)
{
	int i;

	vars->la = len;
	vars->lb = 0;
	vars->na = (int *)malloc(sizeof(int) * len);
	vars->nb = (int *)malloc(sizeof(int) * len);
	vars->nums = (int *)malloc(sizeof(int) * len);
	vars->print_next_command = true;
	i = 0;
	while (i < vars->la)
	{
		vars->nums[i] = ft_atoi(args[i]);
		vars->na[i] = vars->nums[i];
		vars->nb[i] = -1;
		i++;
	}
	bubble_sort(vars->na, vars->la);
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
	//init(&vars, argv, nums_len);
}
