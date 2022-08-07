#ifndef FUNCS_H

# define FUNCS_H

#include "vars.h"

void	px(t_vars *vars, t_stack *from, t_stack *to);

void	sx(t_vars *vars, t_stack *s);
void	ss(t_vars *vars);

void	rx(t_vars *vars, t_stack *s);
void	rr(t_vars *vars);

void	rrx(t_vars *vars, t_stack *s);
void	rrr(t_vars *vars);

#endif
