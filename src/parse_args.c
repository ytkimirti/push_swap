/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42istanbul <@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:27:20 by 42istanbu         #+#    #+#             */
/*   Updated: 2022/08/16 17:49:45 by 42istanbu        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/vector.h"
#include "../libft/libft.h"
#include "render.h"
#include "utils.h"

bool	does_exist(t_ivec *vec, int num)
{
	int	i;

	i = 0;
	while (i < vec->len)
	{
		if (vec->arr[i] == num)
			return (true);
		i++;
	}
	return (false);
}

void	process_number(char *str, t_ivec *vec)
{
	int	num;

	if (!is_integer(str))
		exit_program();
	num = ft_atoi(str);
	free(str);
	if (does_exist(vec, num))
		exit_program();
	ivec_append(vec, num);
}

t_ivec	*parse_args(int argc, const char **argv)
{
	int		i;
	int		j;
	t_ivec	*vec;
	char	**strs;

	vec = ivec_new(64);
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			exit_program();
		strs = ft_split(argv[i], ' ');
		j = 0;
		while (strs[j] != NULL)
		{
			process_number(strs[j], vec);
			j++;
		}
		free(strs);
		i++;
	}
	return (vec);
}
