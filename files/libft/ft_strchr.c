/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:47:31 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 19:48:28 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	ct;

	if (!s)
		return (NULL);
	ct = 0;
	while (s[ct])
	{
		if (s[ct] == (char)c)
			return ((char *)s + ct);
		ct++;
	}
	if (s[ct] == (char)c)
		return ((char *)s + ct);
	return (0);
}
