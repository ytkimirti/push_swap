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

void	render(t_vars *vars, char *move, char stack_name)
{
	if (!vars->print_next_command)
	{
		vars->print_next_command = true;
		return;
	}
	// ft_putstr_fd(move, 1);
	// ft_putstr_fd("\n", 1);
	// BOLD
	if (stack_name == '\0')
	{
		if (LOG)
			ft_printf(BGRN "%s\n" RST, move);
		else
			ft_printf("%s\n", move);
	}
	else
	{
		if (LOG)
			ft_printf(BGRN "%s%c\n" RST, move, stack_name);
		else
			ft_printf("%s%c\n", move, stack_name);
	}
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

	if (!LOG)
		return;
	max = vars->a->len;
	if (vars->b->len > max)
		max = vars->b->len;
	i = 0;
	ft_printf("a\tb\n");
	ft_printf("-\t-\n");
	while (i < max)
	{
		if (i < vars->a->len)
			ft_printf("%d", vars->a->nums[i]);
		else
			ft_printf(" ");
		ft_printf("\t");
		if (i < vars->b->len)
			ft_printf("%d", vars->b->nums[i]);
		else
			ft_printf(" ");
		ft_printf("\n");
		i++;
	}
}
