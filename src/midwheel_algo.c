#include "vars.h"
#include "utils.h"
#include "funcs.h"
#include "render.h"
#include "../libft/libft.h"
#include "../libft/colors.h"

void midwheel_algo(t_vars *vars)
{
	int	middle;
	print_stacks(vars);


	while (vars->lb != 0 || !is_sorted(vars->na, vars->la))
	{
		// Run loop

		// Send all of A to B
		while (vars->la > 2)
		{
			middle = find_middle(vars->na, vars->la);
			ft_printf(BYEL "middle is: %d\n" RST, middle);

			while (vars->na[find_min(vars->na, vars->la)] < middle)
			{
				if (vars->na[0] < middle)
					pb(vars);
				else if (vars->na[vars->la - 1] < middle)
				{
					rra(vars);
					pb(vars);
				}
				else
					ra(vars);
				print_stacks(vars);
			}
		}
		// Sort the ones left behind
		if (vars->la == 2 && vars->na[0] > vars->na[1])
			sa(vars);
		return;
	}
	ft_printf("Sorting finished\n");
}
