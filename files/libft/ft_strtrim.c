/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:38:07 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 21:08:55 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		ct[2];
	int		ascii[256];

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_substr(s1, 0, ft_strlen(s1)));
	ct[0] = -1;
	while (++ct[0] < 256)
		ascii[ct[0]] = 0;
	ct[0] = -1;
	while (set[++ct[0]])
		ascii[(int)set[ct[0]]]++;
	ct[0] = -1;
	while (s1[++ct[0]])
		if (ascii[(int)s1[ct[0]]] == 0)
			break ;
	ct[1] = ft_strlen(s1);
	while (--ct[1] >= 0)
		if (ascii[(int)s1[ct[1]]] == 0)
			break ;
	return (ft_substr(s1, ct[0], ct[1] - ct[0] + 1));
}
