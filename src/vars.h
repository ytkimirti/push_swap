/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42istanbul <@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:27:41 by 42istanbu         #+#    #+#             */
/*   Updated: 2022/08/16 18:14:35 by ykimirti         ###   ########.tr       */
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
	bool	is_checker;
	t_stack	*a;
	t_stack	*b;
	t_ivec	*chunks;
}	t_vars;

#endif
