/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:43:07 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 23:00:17 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new || !lst)
	{
		ft_putstr_fd("ERROR_IN_FT_LSTADD_BACK\n", 1);
		return (0);
	}
	temp = ft_lstlast(*lst);
	if (!temp)
	{
		*lst = new;
		return (1);
	}
	temp->next = new;
	return (1);
}
