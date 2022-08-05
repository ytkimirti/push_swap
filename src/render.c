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


#include "vars.h"
#include "../libft/libft.h"
#include "../libft/colors.h"

void	render(t_vars *vars, char *move)
{
	if (!vars->print_next_command)
	{
		vars->print_next_command = true;
		return;
	}
	// ft_putstr_fd(move, 1);
	// ft_putstr_fd("\n", 1);
	// BOLD
	ft_printf(BGRN "%s\n" RST, move);
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
	ft_printf("a\tb\n");
	ft_printf("-\t-\n");
	while (i < max)
	{
		if (i < vars->la)
			ft_printf("%d", vars->na[i]);
		else
			ft_printf(" ");
		ft_printf("\t");
		if (i < vars->lb)
			ft_printf("%d", vars->nb[i]);
		else
			ft_printf(" ");
		ft_printf("\n");
		i++;
	}
}
