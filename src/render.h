/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42istanbul <@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:27:24 by 42istanbu         #+#    #+#             */
/*   Updated: 2022/08/16 15:45:18 by 42istanbu        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H

# define RENDER_H

# include "vars.h"

void	render(t_vars *vars, char *cmd, char stack_name);
void	exit_program(void);
void	print_stacks(t_vars *vars);
void	print_chunks(t_vars *vars, t_stack *stack);

#endif
