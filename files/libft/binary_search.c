/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 21:01:53 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 19:46:41 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	binary_search(int *arr, int arr_size, int target)
{
	int	lb;
	int	ub;
	int	mid;

	lb = -1;
	ub = arr_size;
	while (ub - lb > 1)
	{
		mid = (ub + lb) / 2;
		if (arr[mid] < target)
			lb = mid;
		else if (arr[mid] > target)
			ub = mid;
		else
			return (mid);
	}
	return (-1);
}
