/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:21:06 by ykimirti          #+#    #+#             */
/*   Updated: 2022/02/14 16:37:27 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */


#include "vars.h"
#include "render.h"

void	sa(t_vars *vars)
{
	int	c;

	if (vars->la < 2)
		return ;
	c = vars->na[0];
	vars->na[0] = vars->na[1];
	vars->na[1] = c;
	render(vars, "sa");
}

void	sb(t_vars *vars)
{
	int	c;

	if (vars->lb < 2)
		return ;
	c = vars->nb[0];
	vars->nb[0] = vars->nb[1];
	vars->nb[1] = c;
	render(vars, "sb");
}

void	ss(t_vars *vars)
{
	vars->print_next_command = false;
	sa(vars);
	vars->print_next_command = false;
	sb(vars);
	render(vars, "ss");
}
