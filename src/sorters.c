/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:44:24 by ykimirti          #+#    #+#             */
/*   Updated: 2022/08/16 15:46:50 by 42istanbu        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "vars.h"
#include "funcs.h"
#include "utils.h"

void	sort_triple(t_vars *vars, t_stack *s)
{
	int		max_pos;
	int		min_pos;

	max_pos = find_max(s->nums, s->len);
	min_pos = find_min(s->nums, s->len);
	if (min_pos == 0 && max_pos == 1)
	{
		rrx(vars, s);
		sx(vars, s);
	}
	else if (min_pos == 2 && max_pos == 0)
	{
		rx(vars, s);
		sx(vars, s);
	}
	else if (min_pos == 1 && max_pos == 2)
		sx(vars, s);
	else if (min_pos == 1 && max_pos == 0)
		rx(vars, s);
	else if (min_pos == 2 && max_pos == 1)
		rrx(vars, s);
}

void	send_to_a(t_vars *vars, t_stack *s)
{
	int	min;
	int	max;
	int	target;

	while (s->len != 5)
	{
		target = s->other->nums[0];
		max = s->nums[find_max(s->nums, s->len)];
		min = s->nums[find_min(s->nums, s->len)];
		if ((target > s->nums[s->len - 1] && target < s->nums[0])
			|| (target > max && s->nums[s->len - 1] == max)
			|| (target < min && s->nums[0] == min))
			px(vars, s->other, s);
		else
			rx(vars, s);
		print_stacks(vars);
	}
}

void	sort_five(t_vars *vars, t_stack *s)
{
	print_stacks(vars);
	px(vars, s, s->other);
	px(vars, s, s->other);
	print_stacks(vars);
	sort_triple(vars, s);
	print_stacks(vars);
	send_to_a(vars, s);
	while (!is_sorted(s->nums, s->len))
	{
		if (find_min(s->nums, s->len) > s->len / 2)
			rrx(vars, s);
		else
			rx(vars, s);
	}
	print_stacks(vars);
}
