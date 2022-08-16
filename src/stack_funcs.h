/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_funcs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42istanbul <@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:27:32 by 42istanbu         #+#    #+#             */
/*   Updated: 2022/08/16 15:27:43 by 42istanbu        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_FUNCS_H

# define STACK_FUNCS_H

# include "vars.h"

void	send_last_elements(t_vars	*vars, t_stack	*from, int *chunk_size);

void	rotate_n_times(t_vars *vars, t_stack *stack, int n);

bool	chunk_ok(t_vars *vars, t_stack *stack, int len, int middle);

#endif
