/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 11:58:49 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 18:55:57 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int n)
{
	long long	lb;
	long long	ub;
	long long	mid;

	if (n <= 1LL)
		return (n);
	lb = 0LL;
	ub = (long long)n;
	while (ub - lb > 1LL)
	{
		mid = (lb + ub) / 2LL;
		if (mid * mid <= (long long)n)
			lb = mid;
		else
			ub = mid;
	}
	return ((int)lb);
}
