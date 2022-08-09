#ifndef STACK_FUNCS_H

# define STACK_FUNCS_H

# include "vars.h"

void	send_last_elements(t_vars	*vars, t_stack	*from, int *chunk_size);

void	rotate_n_times(t_vars *vars, t_stack *stack, int n);

bool	chunk_ok(t_vars *vars, t_stack *stack, int len, int middle);

#endif
