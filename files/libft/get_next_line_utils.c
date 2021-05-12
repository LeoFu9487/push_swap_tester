/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:08:54 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 23:31:31 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sub(t_lst *dst, t_str *str, int len)
{
	t_str	*temp;

	temp = dst->str;
	if (!temp)
	{
		dst->str = str;
		dst->len = len;
		return (1);
	}
	while (temp->next)
		temp = temp->next;
	temp->next = str;
	dst->len += len;
	return (1);
}

int	ft_str_add(t_lst *dst, char *s, int len)
{
	t_str	*str;
	int		idx;

	if (len < 0 || !s)
		return (-1);
	str = ft_malloc(1, sizeof(t_str));
	if (!str)
		return (-1);
	idx = -1;
	str->next = 0;
	str->s = ft_calloc(len + 1, sizeof(char));
	if (!(str->s))
		return (-1);
	while (++idx < len)
		str->s[idx] = s[idx];
	return (ft_sub(dst, str, len));
}

t_lst	*ft_lst_add(t_lst **dst, int fd)
{
	t_lst	*temp;

	temp = ft_malloc(1, sizeof(t_lst));
	if (!temp)
		return (NULL);
	temp->str = 0;
	temp->len = 0;
	temp->fd = fd;
	temp->idx = 0;
	temp->next = 0;
	if (*dst == 0)
		*dst = temp;
	else
	{
		temp->next = *dst;
		*dst = temp;
	}
	return (temp);
}

int	ft_clean_lst(t_lst *lst)
{
	t_str	*temp;

	lst->idx = 0;
	lst->len = 0;
	while (lst->str)
	{
		temp = lst->str;
		lst->str = lst->str->next;
		ft_free(temp->s);
		ft_free(temp);
	}
	lst->str = 0;
	return (0);
}
