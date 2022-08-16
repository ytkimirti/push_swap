/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42istanbul <@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:27:40 by 42istanbu         #+#    #+#             */
/*   Updated: 2022/08/16 15:49:32 by 42istanbu        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H

# define UTILS_H

int		find_middle(const int *nums, int len);

// Returns the index
int		find_min(const int *nums, int len);

// Returns the index
int		find_max(const int *nums, int len);

bool	is_sorted(const int *nums, int len);
bool	is_sorted_descending(const int *nums, int len);

int		*copy_array(const int *nums, int len);
int		*extract_mixed_array(const int *nums, int len,
			int stack_len, int rotate_count);
bool	is_integer(const char *str);

#endif
