#include "vars.h"
#include "utils.h"
#include "funcs.h"
#include "render.h"
#include "../libft/libft.h"
#include "../libft/colors.h"
#include "../libft/vector.h"

int send_chunk(t_vars *vars, t_stack *from, t_stack *to, int chunk_size)
{
	int	middle;
	int	rotate_count;
	int	push_count;
	int	i;

	while (chunk_size != 0)
	{
		middle = find_middle(from->nums, chunk_size);
		rotate_count = 0;
		push_count = 0;
		if (LOG)
			ft_printf(BYEL "chunk_size: %d middle: %d\n" RST, chunk_size, middle);
		print_stacks(vars);
		while (chunk_size > 2 &&
				chunk_size - rotate_count > 0 &&
				((to == vars->b && from->nums[find_min(from->nums, chunk_size - rotate_count)] < middle) ||
				 (to == vars->a && from->nums[find_max(from->nums, chunk_size - rotate_count)] > middle)
				 ))
		{
			if ((to == vars->b && from->nums[0] < middle) || (to == vars->a && from ->nums[0] > middle))
			{
				px(vars, from, to);
				push_count++;
				chunk_size--;
				print_stacks(vars);
			}
			else if (chunk_size == from->len && ((to == vars->b && from->nums[from->len - 1] < middle) || (to == vars->a && from->nums[from->len - 1] > middle)))
			{
				rrx(vars, from);
				px(vars, from, to);
				chunk_size--;
				push_count++;
			}
			else
			{
				rx(vars, from);
				rotate_count++;
				print_stacks(vars);
			}
		}
		if (rotate_count != 0 && LOG)
			ft_printf(YEL "Restoring the rotations on B\n" RST, middle);
		i = 0;
		while (i < rotate_count)
		{
			rrx(vars, from);
			i++;
		}
		print_stacks(vars);
		if (chunk_size == 2)
		{
			if (LOG)
				ft_printf(YEL "Last 2 elements on chunk\n" RST, middle);
			if ((to == vars->b && from->nums[0] > from->nums[1]) || (to == vars->a && from->nums[0] < from->nums[1]))
				sx(vars, from);
			push_count += 2;
			chunk_size -= 2;
			px(vars, from, to);
			px(vars, from, to);
		}
		else if (chunk_size == 1)
		{
			if (LOG)
				ft_printf(YEL "Last element on chunk\n" RST, middle);
			px(vars, from, to);
			push_count++;
			chunk_size--;
		}
		// Divided a chunk into a part, add to the list
		if (LOG)
			ft_printf(BBLU "Sended %d elements, left %d\n" RST, push_count, chunk_size);
		ivec_append(vars->chunks, push_count);
		push_count = 0;
	}
	print_stacks(vars);
	return (rotate_count);
}

void midwheel_algo(t_vars *vars)
{
	t_stack	*curr;
	t_stack	*other;
	t_stack	*tmp;
	t_ivec	*tmp_chunks;
	int			i;

	vars->chunks = ivec_new(64);
	send_chunk(vars, vars->a, vars->b, vars->a->len);
	print_chunks(vars);
	curr = vars->b;
	other = vars->a;
	while(vars->b->len > 0 || !is_sorted(vars->a->nums, vars->a->len))
	{
		if (LOG)
			ft_printf(BMAG "====== %c -> %c =======\n" RST, curr->c, other->c);
		tmp_chunks = ivec_dup(vars->chunks);
		vars->chunks->len = 0;
		i = 0;
		while (i < tmp_chunks->len)
		{
			send_chunk(vars, curr, other, tmp_chunks->arr[tmp_chunks->len - 1 - i]);
			i++;
		}
		ivec_del(tmp_chunks);
		print_chunks(vars);
		tmp = curr;
		curr = other;
		other = tmp;
	}
}


