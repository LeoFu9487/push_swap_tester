/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 11:34:30 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 23:00:21 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
	{
		ft_putstr_fd("ERROR_IN_FT_LSTADD_FRONT\n", 1);
		return (0);
	}
	if (!*lst)
	{
		*lst = new;
		return (1);
	}
	new->next = *lst;
	*lst = new;
	return (1);
}
