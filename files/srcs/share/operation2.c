/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:21:42 by yfu               #+#    #+#             */
/*   Updated: 2021/03/13 23:42:59 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ra(t_deque *stack[2])
{
	void	*ptr;

	if (stack[0]->size == 0)
		return ;
	ptr = stack[0]->tail->content;
	deque_pop_back(stack[0], NULL);
	deque_push_front(stack[0], ptr);
}

void	rb(t_deque *stack[2])
{
	void	*ptr;

	if (stack[1]->size == 0)
		return ;
	ptr = stack[1]->tail->content;
	deque_pop_back(stack[1], NULL);
	deque_push_front(stack[1], ptr);
}

void	rr(t_deque *stack[2])
{
	ra(stack);
	rb(stack);
}

void	rra(t_deque *stack[2])
{
	void	*ptr;

	if (stack[0]->size == 0)
		return ;
	ptr = stack[0]->head->content;
	deque_pop_front(stack[0], NULL);
	deque_push_back(stack[0], ptr);
}

void	rrb(t_deque *stack[2])
{
	void	*ptr;

	if (stack[1]->size == 0)
		return ;
	ptr = stack[1]->head->content;
	deque_pop_front(stack[1], NULL);
	deque_push_back(stack[1], ptr);
}
