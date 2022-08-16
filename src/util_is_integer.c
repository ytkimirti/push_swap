/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_is_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42istanbul <@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:27:33 by 42istanbu         #+#    #+#             */
/*   Updated: 2022/08/16 15:27:43 by 42istanbu        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>

// Takes a string and check if that thing is
// an integer.
bool	is_integer(const char *str)
{
	int				sign;
	int				i;
	long long	nb;

	i = 0;
	nb = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		if (nb > INT_MAX && sign == 1)
			return (false);
		if (nb * sign < INT_MIN && sign == -1)
			return (false);
		i++;
	}
	if (str[i] != '\0')
		return (false);
	return (true);
}
