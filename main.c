#include "push_swap.h"

void init(t_vars *vars, const int *args, int len)
{
	int i;

	vars->la = len;
	vars->lb = 0;
	vars->nb = (int *)malloc(sizeof(int) * len);
	vars->na = (int *)malloc(sizeof(int) * len);
	vars->print_next_command = true;
	i = 0;
	while (i < vars->la)
	{
		vars->na[i] = args[i];
		vars->nb[i] = 1010101;
		i++;
	}
	render(vars, "init");
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

	ft_printf("Initing shit");
}
