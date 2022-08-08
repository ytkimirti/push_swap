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

#include "vars.h"
#include "funcs.h"
#include "utils.h"

void	sort_triple(t_vars *vars, t_stack *s)
{
	int		max_pos;
	int		min_pos;

	max_pos = find_max(s->nums, s->len);
	min_pos = find_min(s->nums, s->len);
	if (min_pos == 0 && max_pos == 1)
	{
		rrx(vars, s);
		sx(vars, s);
	}
	else if (min_pos == 2 && max_pos == 0)
	{
		rx(vars, s);
		sx(vars, s);
	}
	else if (min_pos == 1 && max_pos == 2)
		sx(vars, s);
	else if (min_pos == 1 && max_pos == 0)
		rx(vars, s);
	else if (min_pos == 2 && max_pos == 1)
		rrx(vars, s);
}
