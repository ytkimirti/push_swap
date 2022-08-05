#include "render.h"
#include "vars.h"
#include "bubble_sort.h"
#include "../libft/libft.h"

void init(t_vars *vars, const char *args[], int len)
{
	int i;
	int j;

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
		vars->nb[i] = 9999;

		j = 0;
		while (j < i)
			if (vars->na[i] == vars->na[j++])
				exit_program();
		i++;
	}
	bubble_sort(vars->nums, vars->la);
}
