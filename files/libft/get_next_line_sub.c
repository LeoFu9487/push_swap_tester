/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_sub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 23:31:09 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 23:32:52 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sub(t_lst *target, t_lst **head, int *res)
{
	if (target->str)
		ft_clean_lst(target);
	if (target->next)
		*head = target->next;
	else
		*head = 0;
	ft_free(target);
	if (res[1] == -1)
		return (-1);
	return (res[1] && res[0]);
}

int	ft_del_lst(t_lst *target, t_lst **head, int *res)
{
	t_lst	*temp;

	if (res[1] != -1 && target->len)
		return (1);
	if (target == *head)
		return (sub(target, head, res));
	temp = *head;
	while (temp->next != target)
		temp = temp->next;
	temp->next = target->next;
	if (target->str)
		ft_clean_lst(target);
	ft_free(target);
	if (res[1] == -1)
		return (-1);
	return (res[1] == res[0]);
}
