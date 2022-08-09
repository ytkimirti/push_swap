#include "../libft/colors.h"
#include "../libft/libft.h"
#include "../libft/vector.h"
#include "funcs.h"
#include "render.h"
#include "utils.h"
#include "vars.h"

void	send_last_elements(t_vars	*vars, t_stack	*from, int *chunk_size)
{
	if (*chunk_size == 2)
	{
		if (LOG)
			ft_printf(YEL "Last 2 elements on chunk %c\n" RST, from->c);
		if ((from == vars->a && from->nums[0] > from->nums[1])
			|| (from == vars->b && from->nums[0] < from->nums[1]))
			sx(vars, from);
		px(vars, from, from->other);
		px(vars, from, from->other);
		*chunk_size -= 2;
	}
	else if (*chunk_size == 1)
	{
		if (LOG)
			ft_printf(YEL "Last elements on chunk %c\n" RST, from->c);
		px(vars, from, from->other);
		*chunk_size -= 1;
	}
}

void	rotate_n_times(t_vars *vars, t_stack *stack, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rrx(vars, stack);
		i++;
	}
}

bool	chunk_ok(t_vars *vars, t_stack *stack, int len, int middle)
{
	if (stack == vars->a)
		return (stack->nums[find_min(stack->nums, len)] >= middle);
	else
		return (stack->nums[find_max(stack->nums, len)] <= middle);
}
