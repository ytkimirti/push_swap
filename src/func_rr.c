/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:22:42 by ykimirti          #+#    #+#             */
/*   Updated: 2022/08/16 15:39:22 by 42istanbu        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars.h"
#include "render.h"

// Reverse rotate X
void	rrx(t_vars *vars, t_stack *s)
{
	int	last;
	int	i;

	if (s->len < 2)
		return ;
	last = s->nums[s->len - 1];
	i = s->len - 1;
	while (i > 0)
	{
		s->nums[i] = s->nums[i - 1];
		i--;
	}
	s->nums[0] = last;
	render(vars, "rr", s->c);
}

// Reverse rotate both
void	rrr(t_vars *vars)
{
	vars->print_next_command = false;
	rrx(vars, vars->a);
	vars->print_next_command = false;
	rrx(vars, vars->b);
	render(vars, "rrr", '\0');
}
