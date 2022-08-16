/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_is_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42istanbul <@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:27:35 by 42istanbu         #+#    #+#             */
/*   Updated: 2022/08/16 15:27:43 by 42istanbu        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	is_sorted(const int *nums, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (nums[i] >= nums[i + 1])
			return (false);
		i++;
	}
	return (true);
}

bool	is_sorted_descending(const int *nums, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (nums[i] <= nums[i + 1])
			return (false);
		i++;
	}
	return (true);
}
