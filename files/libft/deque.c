/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:46:06 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 23:08:13 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_deque	*deque_init(void)
{
	t_deque	*deque;

	deque = ft_malloc(1, sizeof(t_deque));
	if (!deque)
		return (deque);
	deque->head = NULL;
	deque->tail = NULL;
	deque->size = 0;
	return (deque);
}

void	deque_push_back(t_deque *deque, void *ptr)
{
	t_double_list	*temp;

	(deque->size)++;
	temp = double_list_init(ptr);
	if (!temp)
		return ;
	if (deque->size == 1)
	{
		deque->head = temp;
		deque->tail = temp;
		return ;
	}
	temp->last = deque->tail;
	deque->tail->next = temp;
	deque->tail = deque->tail->next;
}

void	deque_push_front(t_deque *deque, void *ptr)
{
	t_double_list	*temp;

	(deque->size)++;
	temp = double_list_init(ptr);
	if (!temp)
		return ;
	if (deque->size == 1)
	{
		deque->head = temp;
		deque->tail = temp;
		return ;
	}
	temp->next = deque->head;
	deque->head->last = temp;
	deque->head = deque->head->last;
}

void	deque_pop_back(t_deque *deque, void (*f)(void *))
{
	t_double_list	*temp;

	if (deque->size < 1 || !deque->tail)
		return ;
	(deque->size)--;
	temp = deque->tail;
	deque->tail = deque->tail->last;
	if (deque->tail)
		deque->tail->next = NULL;
	if (f)
		f(temp->content);
	ft_free(temp);
}

void	deque_pop_front(t_deque *deque, void (*f)(void*))
{
	t_double_list	*temp;

	if (deque->size < 1 || !deque->head)
		return ;
	(deque->size)--;
	temp = deque->head;
	deque->head = deque->head->next;
	if (deque->head)
		deque->head->last = NULL;
	if (f)
		f(temp->content);
	ft_free(temp);
}
