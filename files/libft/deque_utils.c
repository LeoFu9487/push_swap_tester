/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:58:29 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 19:49:04 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_double_list	*double_list_init(void *ptr)
{
	t_double_list	*double_list;

	double_list = ft_malloc(1, sizeof(t_double_list));
	if (!double_list)
		return (NULL);
	double_list->content = ptr;
	double_list->next = NULL;
	double_list->last = NULL;
	return (double_list);
}

void	deque_clear(t_deque *deque, void (*f)(void*))
{
	while (deque->size)
		deque_pop_back(deque, f);
}
