#include "vars.h"
#include "utils.h"
#include "funcs.h"
#include "render.h"
#include "../libft/libft.h"
#include "../libft/colors.h"
#include "../libft/vector.h"

int send_chunk_to_b(t_vars *vars)
{
	int middle;
	int	push_count;

	middle = find_middle(vars->na, vars->la);
	if (LOG)
		ft_printf(BYEL "middle is: %d\n" RST, middle);
	push_count = 0;
	while (vars->la > 2 && vars->na[find_min(vars->na, vars->la)] < middle)
	{
		if (vars->na[0] < middle)
		{
			pb(vars);
			push_count++;
		}
		else if (vars->na[vars->la - 1] < middle)
		{
			rra(vars);
			pb(vars);
			push_count++;
		}
		else
			ra(vars);
		print_stacks(vars);
	}
	return (push_count);
}

int send_chunk_to_a(t_vars *vars, int chunk_size)
{
	// TODO: Add last chunk not restoring rotations!
	int	middle;
	int	rotate_count;
	int	push_count;
	int	i;

	push_count = 0;
	while (chunk_size - push_count != 0)
	{
		rotate_count = 0;
		middle = find_middle(vars->nb, chunk_size - push_count);
		if (LOG)
			ft_printf(BYEL "chunk_size: %d push_count: %d middle: %d\n" RST, chunk_size, push_count, middle);
		print_stacks(vars);
		while (chunk_size - push_count > 2 && vars->nb[find_max(vars->nb, chunk_size - rotate_count - push_count)] > middle)
		{
			if (vars->nb[0] > middle)
			{
				pa(vars);
				push_count++;
				print_stacks(vars);
			}
			else
			{
				rb(vars);
				print_stacks(vars);
				rotate_count++;
			}
		}
		if (rotate_count != 0 && LOG)
			ft_printf(YEL "Restoring the rotations on B\n" RST, middle);
		i = 0;
		while (i < rotate_count)
		{
			rrb(vars);
			print_stacks(vars);
			i++;
		}
		if (chunk_size - push_count == 2)
		{
			if (LOG)
				ft_printf(YEL "Last 2 elements on chunk\n" RST, middle);
			if (vars->nb[0] < vars->nb[1])
				sb(vars);
			pa(vars);
			pa(vars);
			push_count += 2;
		}
		else if (chunk_size - push_count == 1)
		{
			if (LOG)
				ft_printf(YEL "Last element on chunk\n" RST, middle);
			pa(vars);
			push_count += 1;
		}
	}
	return (rotate_count);
}

void midwheel_algo(t_vars *vars)
{
	t_ivec	*chunk_sizes;
	int			i;

	while (vars->lb != 0 || !is_sorted(vars->na, vars->la))
	{
		chunk_sizes = ivec_new(64);
		if (LOG)
			print_stacks(vars);
		// Run loop


		// Send all of A to B
		while (vars->la > 2)
			ivec_append(chunk_sizes, send_chunk_to_b(vars));
		// Sort the ones left behind
		if (vars->la == 2 && vars->na[0] > vars->na[1])
		{
			if (LOG)
				ft_printf(YEL "Last two is not sorted, sorting...\n" RST);
			sa(vars);
			print_stacks(vars);
		}
		i = 0;
		// Send from B to A using midwheel
		if (LOG)
			ft_printf(BMAG "Sending to A\n" RST);
		while (vars->lb != 0)
		{
			send_chunk_to_a(vars, chunk_sizes->arr[chunk_sizes->len - 1 - i]);
			i++;
		}
	}
	if (LOG)
		ft_printf("Sorting finished\n");
}

