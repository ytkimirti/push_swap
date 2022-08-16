/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:21:06 by ykimirti          #+#    #+#             */
/*   Updated: 2022/08/16 15:39:33 by 42istanbu        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars.h"
#include "render.h"

// Swap X
void	sx(t_vars *vars, t_stack *s)
{
	int	c;

	if (s->len < 2)
		return ;
	c = s->nums[0];
	s->nums[0] = s->nums[1];
	s->nums[1] = c;
	render(vars, "s", s->c);
}

// Swap both
void	ss(t_vars *vars)
{
	vars->print_next_command = false;
	sx(vars, vars->a);
	vars->print_next_command = false;
	sx(vars, vars->b);
	render(vars, "ss", '\0');
}
