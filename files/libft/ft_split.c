/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:38:31 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 21:56:00 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cnt(char const *s, char c)
{
	int		ct[2];

	if (!s)
		return (-1);
	ct[0] = 0;
	ct[1] = 0;
	while (s[ct[0]])
	{
		while (s[ct[0]] && s[ct[0]] == c)
			ct[0]++;
		if (!s[ct[0]])
			break ;
		while (s[ct[0]] && s[ct[0]] != c)
			ct[0]++;
		ct[1]++;
	}
	return (ct[1]);
}

static int	ft_sub(char **ans, const char *s, int *ct)
{
	ans[ct[1]++] = ft_substr(s, ct[0] - ct[2], ct[2]);
	if (!ans[ct[1] - 1])
		return (0);
	return (1);
}

static char	**ft_free_sub(char **ans)
{
	int	ct;

	ct = -1;
	while (ans[++ct])
		ft_memory(0, 0, ans[ct], pop);
	ft_memory(0, 0, ans, pop);
	return (NULL);
}

static void	norm(int *ct)
{
	ct[0] = 0;
	ct[1] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	int		sz;
	int		ct[3];

	if (!s)
		return (NULL);
	sz = ft_cnt(s, c);
	ans = ft_calloc(sizeof(char *), sz + 1);
	if (!ans)
		return (NULL);
	norm(ct);
	while (s[ct[0]])
	{
		ct[2] = 0;
		while (s[ct[0]] && s[ct[0]] == c)
			ct[0]++;
		while (s[ct[0]] && s[ct[0]] != c)
		{
			ct[0]++;
			ct[2]++;
		}
		if (ct[2] > 0 && !ft_sub(ans, s, (int *)ct))
			return (ft_free_sub(ans));
	}
	return (ans);
}
