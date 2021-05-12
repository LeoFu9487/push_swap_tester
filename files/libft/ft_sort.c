/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:01:35 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 22:00:06 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ascending(int a, int b)
{
	return (a < b);
}

int	ft_descending(int a, int b)
{
	return (a > b);
}

static void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	ft_deep(int *arr, int index, int nbr, int (*cmp)(int, int))
{
	int	temp_index;

	if (index * 2 + 1 >= nbr)
		return ;
	if (index * 2 + 2 >= nbr)
		temp_index = index * 2 + 1;
	else
	{
		if (cmp(arr[index * 2 + 1], arr[index * 2 + 2]))
			temp_index = index * 2 + 2;
		else
			temp_index = index * 2 + 1;
	}
	if (cmp(arr[temp_index], arr[index]))
		return ;
	ft_swap(arr + index, arr + temp_index);
	ft_deep(arr, temp_index, nbr, cmp);
}

void	ft_sort(int *head, int *tail, int (*cmp)(int, int))
{
	int		*arr;
	int		nbr;
	int		ct;

	if (!cmp)
		cmp = ft_ascending;
	arr = head;
	nbr = (int)(tail - head);
	ct = nbr;
	while (--ct >= 0)
		ft_deep(arr, ct, nbr, cmp);
	while (--nbr >= 1)
	{
		ft_swap(arr + nbr, arr);
		ft_deep(arr, 0, nbr, cmp);
	}
}
