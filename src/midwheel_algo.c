#include "vars.h"
#include "utils.h"
#include "funcs.h"
#include "render.h"
#include "../libft/libft.h"

void midwheel_algo(t_vars *vars)
{
	int	middle;
	print_stacks(vars);
	return;

	while (vars->lb != 0 || !is_sorted(vars->na, vars->la))
	{
		// Run loop

		// Send all of A to B
		while (vars->la != 0)
		{
			middle = find_middle(vars->na, vars->la);

			while (vars->na[find_min(vars->na, vars->la)] < middle)
			{
				if (vars->na[0] < middle)
					pb(vars);
				else if (vars->na[vars->la - 1] < middle)
				{
					rra(vars);
					pb(vars);
				}
			}
		}
	}
	ft_printf("Sorting finished\n");
}
