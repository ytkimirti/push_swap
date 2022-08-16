/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:22:57 by ykimirti          #+#    #+#             */
/*   Updated: 2022/08/16 15:27:43 by 42istanbu        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */


#include "vars.h"
#include "render.h"

// Push to X
void	px(t_vars *vars, t_stack *from, t_stack *to)
{
	int i;

	if (from->len < 1)
		return ;
	to->len++;
	i = to->len - 1;
	while (i > 0)
	{
		to->nums[i] = to->nums[i - 1];
		i--;
	}
	to->nums[0] = from->nums[0];
	i = 1;
	while (i < from->len)
	{
		from->nums[i - 1] = from->nums[i];
		i++;
	}
	from->len--;
	render(vars, "p", to->c);
}
