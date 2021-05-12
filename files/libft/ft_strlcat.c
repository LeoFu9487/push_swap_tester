/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:36:12 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 19:44:01 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (ft_strlen(s2));
	i = 0;
	while (s1[i] != '\0' && i < n)
		i++;
	j = i;
	while (i < n - 1 && s2[i - j] != '\0')
	{
		s1[i] = s2[i - j];
		i++;
	}
	if (j < n)
		s1[i] = '\0';
	return (j + ft_strlen(s2));
}

void	ft_strcat(char *s1, char *s2)
{
	int	n;
	int	i;

	n = ft_strlen(s1);
	i = 0;
	while (s2[i])
	{
		s1[n + i] = s2[i];
		i++;
	}
	s1[n + i] = '\0';
}
