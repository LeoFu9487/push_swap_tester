/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:44:11 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 21:03:25 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ans;
	int		len;
	int		ct;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	ans = ft_memory(len + 1, sizeof(char), 0, push);
	if (!ans)
		return (NULL);
	ct = -1;
	while (++ct < len)
		ans[ct] = f(ct, s[ct]);
	ans[ct] = '\0';
	return (ans);
}
