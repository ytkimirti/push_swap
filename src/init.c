/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42istanbul <@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:18:54 by 42istanbu         #+#    #+#             */
/*   Updated: 2022/08/16 16:18:55 by 42istanbu        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars.h"
#include "render.h"
#include <stdlib.h>

void	init(t_vars *vars, t_ivec *nums)
{
	int	i;

	vars->a = (t_stack *)malloc(sizeof(t_stack));
	vars->b = (t_stack *)malloc(sizeof(t_stack));
	if (!vars->a || !vars->b)
		exit_program();
	vars->a->other = vars->b;
	vars->b->other = vars->a;
	vars->a->nums = (int *)malloc(sizeof(int) * nums->len);
	vars->b->nums = (int *)malloc(sizeof(int) * nums->len);
	if (!vars->a->nums || !vars->b->nums)
		exit_program();
	vars->a->len = nums->len;
	vars->a->c = 'a';
	vars->b->len = 0;
	vars->b->c = 'b';
	vars->chunks = NULL;
	vars->print_next_command = true;
	i = 0;
	while (i < nums->len)
	{
		vars->a->nums[i] = nums->arr[i];
		i++;
	}
}
