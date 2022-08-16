/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midwheel_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42istanbul <@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:27:18 by 42istanbu         #+#    #+#             */
/*   Updated: 2022/08/16 15:27:43 by 42istanbu        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/colors.h"
#include "../libft/libft.h"
#include "../libft/vector.h"
#include "funcs.h"
#include "render.h"
#include "utils.h"
#include "vars.h"
#include "stack_funcs.h"

// Returns number of pushes happening in this function
// Incremenets the rotate count variable (i know it looks bad)
// NOTE: Remove chunk size from here and see if it works
int	send_element(t_vars *vars, t_stack *stack, int middle, int *rotate_count)
{
	if ((stack == vars->a && stack->nums[0] < middle)
		|| (stack == vars->b && stack->nums[0] > middle))
	{
		px(vars, stack, stack->other);
		print_stacks(vars);
		return (1);
	}
	else if (
		((stack == vars->a && stack->nums[stack->len - 1] < middle)
			|| (stack == vars->b && stack->nums[stack->len - 1] > middle)))
	{
		rrx(vars, stack);
		px(vars, stack, stack->other);
		print_stacks(vars);
		return (1);
	}
	else
	{
		rx(vars, stack);
		*rotate_count += 1;
		print_stacks(vars);
	}
	return (0);
}

// Modifies the chunk_size while sending it
void	send_middle(t_vars *vars, t_stack *stack,
		int *chunk_size)
{
	int		rotate_count;
	int		middle;
	bool	need_rotations;

	rotate_count = 0;
	middle = find_middle(stack->nums, *chunk_size);
	need_rotations = *chunk_size != stack->len;
	if (LOG)
		ft_printf("on %c -> chunk_size: " YEL "%d" RST
			" middle: " YEL "%d" RST "\n", stack->c, *chunk_size, middle);
	print_stacks(vars);
	while (*chunk_size > 2 && *chunk_size - rotate_count > 0
		&& !chunk_ok(vars, stack, *chunk_size - rotate_count, middle))
		*chunk_size -= send_element(vars, stack, middle, &rotate_count);
	if (need_rotations)
		rotate_n_times(vars, stack, rotate_count);
	send_last_elements(vars, stack, chunk_size);
}

void	send_chunk(t_vars *vars, t_stack *from, int chunk_size)
{
	int	mem_chunk_size;

	while (chunk_size != 0)
	{
		if ((from == vars->a && is_sorted(vars->a->nums, vars->a->len))
			|| (from == vars->b
				&& is_sorted_descending(vars->b->nums, vars->b->len)))
		{
			if (LOG)
				ft_printf(BBLU "Stack a is already sorted, "
					"skipping chunk %d\n" RST, chunk_size);
			return ;
		}
		mem_chunk_size = chunk_size;
		send_middle(vars, from, &chunk_size);
		if (LOG)
			ft_printf(BBLU "Sended %d elements, left %d\n" RST,
				mem_chunk_size - chunk_size, chunk_size);
		ivec_append(vars->chunks, mem_chunk_size - chunk_size);
	}
	print_stacks(vars);
}

void	midwheel_algo(t_vars *vars)
{
	t_stack	*stack;
	t_ivec	*tmp_chunks;
	int		i;

	vars->chunks = ivec_new(64);
	send_chunk(vars, vars->a, vars->a->len);
	print_chunks(vars, vars->b);
	stack = vars->b;
	while (!is_sorted(vars->a->nums, vars->a->len)
		|| !is_sorted_descending(vars->b->nums, vars->b->len))
	{
		if (LOG)
			ft_printf(BMAG "====== %c -> %c =======\n" RST,
				stack->c, stack->other->c);
		tmp_chunks = ivec_dup(vars->chunks);
		vars->chunks->len = 0;
		i = tmp_chunks->len - 1;
		while (i >= 0)
			send_chunk(vars, stack, tmp_chunks->arr[i--]);
		ivec_del(tmp_chunks);
		print_chunks(vars, stack->other);
		stack = stack->other;
	}
	while (vars->b->len != 0)
		px(vars, vars->b, vars->a);
}
