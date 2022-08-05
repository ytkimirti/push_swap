/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:47:40 by ykimirti          #+#    #+#             */
/*   Updated: 2022/03/08 17:27:47 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void	render(t_vars *vars, char *move)
{
	if (!vars->print_next_command)
	{
		vars->print_next_command = true;
		return;
	}
	ft_putstr_fd(move, 1);
	ft_putstr_fd("\n", 1);
}

void exit_program()
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	print_stacks(t_vars *vars)
{
	int	max;
	int	i;

	max = vars->la;
	if (vars->lb > max)
		max = vars->lb;
	i = 0;
	while (i < max)
	{
		i++;
	}
}
