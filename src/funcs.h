/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42istanbul <@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:27:15 by 42istanbu         #+#    #+#             */
/*   Updated: 2022/08/16 15:27:43 by 42istanbu        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

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
