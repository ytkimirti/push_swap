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
	int	i;

	if (!vars->print_next_command)
	{
		vars->print_next_command = true;
		return;
	}
	ft_putstr_fd(move, 1);
	ft_putstr_fd("\n", 1);
	i = 0;
}


