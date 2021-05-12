/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 13:00:51 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 21:59:26 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*ans;
	size_t	l;
	size_t	ct;

	if (start >= ft_strlen(s))
	{
		ans = ft_calloc(1, sizeof(char));
		return (ans);
	}
	l = (size_t)ft_min((int)(ft_strlen(s) - start), (int)len);
	if (!s)
		return (NULL);
	ans = ft_calloc(l + 1, sizeof(char));
	if (!ans)
		return (NULL);
	ct = -1;
	while (++ct < l)
		ans[ct] = s[start + ct];
	ans[ct] = '\0';
	return (ans);
}
