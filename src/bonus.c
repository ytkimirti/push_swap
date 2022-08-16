/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <ykimirti@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:17:37 by ykimirti          #+#    #+#             */
/*   Updated: 2022/08/16 18:19:27 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_args.h"
#include "funcs.h"
#include "vars.h"
#include "../libft/libft.h"
#include <stdio.h>
#include "render.h"
#include "init.h"
#include "utils.h"

#define BUFFER_SIZE 10

void	execute_cmd(t_vars *vars, char *cmd)
{
	if (!ft_strncmp(cmd, "ss\n", 5))
		ss(vars);
	else if (!ft_strncmp(cmd, "sa\n", 5))
		sx(vars, vars->a);
	else if (!ft_strncmp(cmd, "sb\n", 5))
		sx(vars, vars->b);
	else if (!ft_strncmp(cmd, "pa\n", 5))
		px(vars, vars->b, vars->a);
	else if (!ft_strncmp(cmd, "pb\n", 5))
		px(vars, vars->a, vars->b);
	else if (!ft_strncmp(cmd, "ra\n", 5))
		rx(vars, vars->a);
	else if (!ft_strncmp(cmd, "rb\n", 5))
		rx(vars, vars->b);
	else if (!ft_strncmp(cmd, "rr\n", 5))
		rr(vars);
	else if (!ft_strncmp(cmd, "rra\n", 5))
		rrx(vars, vars->a);
	else if (!ft_strncmp(cmd, "rrb\n", 5))
		rrx(vars, vars->b);
	else if (!ft_strncmp(cmd, "rrr\n", 5))
		rrr(vars);
	else
		exit_program();
}

int	main(int argc, const char *argv[])
{
	t_vars	vars;
	t_ivec	*parsed_args;
	char	*cmd;

	parsed_args = parse_args(argc, argv);
	init(&vars, parsed_args);
	vars.is_checker = true;
	ivec_del(parsed_args);
	while (true)
	{
		cmd = get_next_line(0);
		if (cmd == NULL)
			break ;
		execute_cmd(&vars, cmd);
	}
	if (is_sorted(vars.a->nums, vars.a->len) && vars.b->len == 0)
		ft_printf("OK\n");
	else
		ko_program();
}
