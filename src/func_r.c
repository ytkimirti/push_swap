/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:22:51 by ykimirti          #+#    #+#             */
/*   Updated: 2022/08/16 15:39:18 by 42istanbu        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars.h"
#include "render.h"

// Rotate X
void	rx(t_vars *vars, t_stack *s)
{
	int	first;
	int	i;

	if (s->len < 2)
		return ;
	i = 0;
	first = s->nums[0];
	while (i < s->len - 1)
	{
		s->nums[i] = s->nums[i + 1];
		i++;
	}
	s->nums[s->len - 1] = first;
	render(vars, "r", s->c);
}

// Rotate both
void	rr(t_vars *vars)
{
	vars->print_next_command = false;
	rx(vars, vars->a);
	vars->print_next_command = false;
	rx(vars, vars->b);
	render(vars, "rr", '\0');
}
