/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_triple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:44:24 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/21 19:47:29 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include "funcs.h"

void	sort_tiple(t_vars *vars)
{
	int		max_pos;
	int		min_pos;

	max_pos = find_max(vars->na, vars->la);
	min_pos = find_min(vars->na, vars->la);

	/*ft_printf(BYEL "min: %d max: %d\n" RST, min_pos, max_pos);*/

	if (min_pos == 0 && max_pos == 1)
	{
		rra(vars);
		sa(vars);
	}
	else if (min_pos == 2 && max_pos == 0)
	{
		ra(vars);
		sa(vars);
	}
	else if (min_pos == 1 && max_pos == 2)
		sa(vars);
	else if (min_pos == 1 && max_pos == 0)
		ra(vars);
	else if (min_pos == 2 && max_pos == 1)
		rra(vars);
}
