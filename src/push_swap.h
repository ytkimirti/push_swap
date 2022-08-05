/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:47:42 by ykimirti          #+#    #+#             */
/*   Updated: 2022/03/08 17:26:07 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

#include "../libft/libft.h"
#include "../libft/colors.h"
#include <stdbool.h>
#include <limits.h>

typedef struct
{
	int	la;
	int	lb;
	int	*na;
	int	*nb;
	int *nums;
	bool print_next_command;
} t_vars;

void	render(t_vars *vars, char *move);

int		find_min(int nums[], int len);
int		find_max(int nums[], int len);

int check_args(int argc, const char *argv[]);

// Sorters
void	sort_triple(t_vars *vars);

void exit_program();

// Misc
bool is_integer(const char *str);

#endif
