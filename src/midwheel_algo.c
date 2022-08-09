#include "../libft/colors.h"
#include "../libft/libft.h"
#include "../libft/vector.h"
#include "funcs.h"
#include "render.h"
#include "utils.h"
#include "vars.h"

// Returns number of pushes happening in this function
// Incremenets the rotate count variable (i know it looks bad)
// NOTE: Remove chunk size from here and see if it works
int send_element(t_vars *vars, t_stack *stack, int middle, int *rotate_count, int chunk_size)
{
	// if (stack == vars->a)
	// {
	// 	if (stack->nums[0] < middle)
	// 	{
	// 		px(vars, stack, stack->other);
	// 		*rotate_count += 1;
	// 		return (1);
	// 	}
	// 	else if (chunk_size == stack->len && stack->nums[stack->len - 1] < middle)
	// 	{
	// 		rrx(vars, stack);
	// 		px(vars, stack, stack->other);
	// 		return (1)
	// 	}
	// }
	// else
	// {
 //
	// }
	if ((stack == vars->a && stack->nums[0] < middle) ||
			(stack == vars->b && stack->nums[0] > middle))
	{
		px(vars, stack, stack->other);
		print_stacks(vars);
		return (1);
	}
	else if (chunk_size == stack->len &&
			((stack == vars->a && stack->nums[stack->len - 1] < middle) ||
			 (stack == vars->b && stack->nums[stack->len - 1] > middle)))
	{
		rrx(vars, stack);
		px(vars, stack, stack->other);
		print_stacks(vars);
		return (1);
	}
	else {
		rx(vars, stack);
		*rotate_count += 1;
		print_stacks(vars);
	}
	return (0);
}

void	rotate_n_times(t_vars *vars, t_stack *stack, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rrx(vars, stack);
		i++;
	}
}

void	send_last_elements(t_vars	*vars, t_stack	*from, int *chunk_size)
{
	if (*chunk_size == 2)
	{
		if (LOG)
			ft_printf(YEL "Last 2 elements on chunk %c\n" RST, from->c);
		if ((from == vars->a && from->nums[0] > from->nums[1])
			|| (from == vars->b && from->nums[0] < from->nums[1]))
			sx(vars, from);
		px(vars, from, from->other);
		px(vars, from, from->other);
		*chunk_size -= 2;
	}
	else if (*chunk_size == 1)
	{
		if (LOG)
			ft_printf(YEL "Last elements on chunk %c\n" RST, from->c);
		px(vars, from, from->other);
		*chunk_size -= 1;
	}
}

bool	chunk_ok(t_vars *vars, t_stack *stack, int len, int middle)
{
	if (stack == vars->a)
		return (stack->nums[find_min(stack->nums, len)] >= middle);
	else
		return (stack->nums[find_max(stack->nums, len)] <= middle);
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
		ft_printf("on %c -> chunk_size: " YEL "%d" RST " middle: " YEL "%d" RST "\n", stack->c, *chunk_size, middle);
	print_stacks(vars);
	while (*chunk_size > 2 && *chunk_size - rotate_count > 0
		&& !chunk_ok(vars, stack, *chunk_size - rotate_count, middle))
		*chunk_size -= send_element(vars, stack, middle, &rotate_count, *chunk_size);
	if (need_rotations)
		rotate_n_times(vars, stack, rotate_count);
	send_last_elements(vars, stack, chunk_size);
}

void	send_chunk(t_vars *vars, t_stack *from, int chunk_size)
{
	int	mem_chunk_size;

	while (chunk_size != 0)
	{
		// Is already sorted check
		if ((from == vars->a && is_sorted(vars->a->nums, vars->a->len))
			|| (from == vars->b && is_sorted_descending(vars->b->nums, vars->b->len)))
		{
			if (LOG)
				ft_printf(BBLU "Stack a is already sorted, skipping chunk %d\n" RST, chunk_size);
			return ;
		}
		// Send stuff bigger or smaller than middle to other stack, modifies chunk_size
		mem_chunk_size = chunk_size;
		send_middle(vars, from, &chunk_size);
		// Divided a chunk into a part, add len of that part to the list
		if (LOG)
			ft_printf(BBLU "Sended %d elements, left %d\n" RST, mem_chunk_size - chunk_size, chunk_size);
		ivec_append(vars->chunks, mem_chunk_size - chunk_size);
	}
	print_stacks(vars);
}

void midwheel_algo(t_vars * vars) {
	t_stack *stack;
	t_ivec *tmp_chunks;
	int i;

	vars->chunks = ivec_new(64);
	send_chunk(vars, vars->a, vars->a->len);
	print_chunks(vars, vars->b);
	stack = vars->b;
	while (!is_sorted(vars->a->nums, vars->a->len) ||
			!is_sorted_descending(vars->b->nums, vars->b->len))
	{
		if (LOG)
			ft_printf(BMAG "====== %c -> %c =======\n" RST, stack->c, stack->other->c);
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
