/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_minmax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykimirti <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:43:22 by ykimirti          #+#    #+#             */
/*   Updated: 2022/08/16 15:27:43 by 42istanbu        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "vars.h"
#include <limits.h>

int	find_min(const int nums[], int len)
{
	int	min;
	int	min_index;

	min = INT_MAX;
	min_index = -1;
	while (len-- > 0)
	{
		if (nums[len] <= min)
		{
			min = nums[len];
			min_index = len;
		}
	}
	return (min_index);
}

int	find_max(const int nums[], int len)
{
	int	max;
	int	max_index;

	max = INT_MIN;
	max_index = -1;
	while (len-- > 0)
	{
		if (nums[len] >= max)
		{
			max = nums[len];
			max_index = len;
		}
	}
	return (max_index);
}
