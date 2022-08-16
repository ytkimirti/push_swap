/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42istanbul <@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:27:41 by 42istanbu         #+#    #+#             */
/*   Updated: 2022/08/16 15:54:02 by 42istanbu        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H

# define VARS_H

# include <stdbool.h>
# include "../libft/vector.h"

# ifndef LOG

#  define LOG 1

# endif

typedef struct s_stack
{
	int				len;
	char			c;
	int				*nums;
	struct s_stack	*other;
}	t_stack;

typedef struct s_vars
{
	bool	print_next_command;
	t_stack	*a;
	t_stack	*b;
	t_ivec	*chunks;
}	t_vars;

#endif
