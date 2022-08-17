/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42istanbul <@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:26:07 by 42istanbu         #+#    #+#             */
/*   Updated: 2022/08/17 20:58:39 by ykimirti         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorters.h"
#include "parse_args.h"
#include "funcs.h"
#include "midwheel_algo.h"
#include "vars.h"
#include "../libft/libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "render.h"
#include "init.h"

int	main(int argc, const char *argv[])
{
	t_vars	vars;
	t_ivec	*parsed_args;

		parsed_args = parse_args (argc, argv);
	init(&vars, parsed_args);
	vars.is_checker = false;
	ivec_del(parsed_args);
	if (vars.a->len == 3)
		sort_triple(&vars, vars.a);
	else if (vars.a->len == 5)
		sort_five(&vars, vars.a);
	else
		midwheel_algo(&vars);
}
