/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:42:56 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 23:03:29 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cnt(int n)
{
	int	ans;

	ans = 0;
	if (n < 0)
		ans = 1;
	while (n != 0)
	{
		ans++;
		n /= 10;
	}
	return (ans);
}

char	*ft_itoa(int n)
{
	char	*ans;
	int		ct;

	ans = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	ct = ft_cnt(n);
	ans = ft_malloc(ct + 1, sizeof(char));
	if (!ans)
		return (ans);
	if (n < 0)
		ans[0] = '-';
	ans[ct] = '\0';
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		ans[--ct] = n % 10 + '0';
		n /= 10;
	}
	return (ans);
}
