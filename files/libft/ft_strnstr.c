/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:59:45 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 19:41:42 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *needle, size_t len)
{
	char	*haystack;
	size_t	ct[2];

	haystack = (char *)h;
	if (!h)
		return (NULL);
	if (!(*needle))
		return (haystack);
	ct[0] = 0;
	while (ct[0] < len && haystack[ct[0]])
	{
		ct[1] = 0;
		while (needle[ct[1]] && haystack[ct[0] + ct[1]]
			&& needle[ct[1]] == haystack[ct[0] + ct[1]] && ct[0] + ct[1] < len)
			ct[1]++;
		if (needle[ct[1]] == 0)
			return (haystack + ct[0]);
		ct[0]++;
	}
	return (NULL);
}
