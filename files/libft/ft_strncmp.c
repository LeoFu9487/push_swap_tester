/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:46:54 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 23:39:09 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *ss1, const char *ss2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)ss1;
	s2 = (unsigned char *)ss2;
	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (0);
	if (*s1 == 0 || *s2 == 0 || *s1 != *s2)
		return (*s1 - *s2);
	s1++;
	s2++;
	return (ft_strncmp((char *)(s1), (char *)(s2), n - 1));
}
