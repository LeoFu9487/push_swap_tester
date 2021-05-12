/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:21:42 by yfu               #+#    #+#             */
/*   Updated: 2021/05/05 00:00:02 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	rrr(t_deque *stack[2])
{
	rra(stack);
	rrb(stack);
}

void	init_stack(t_deque *stack, int *arr, int arr_size)
{
	int	ct;

	ct = -1;
	while (++ct < arr_size)
		deque_push_front(stack, arr + ct);
}

void	assigned_operation(void *ptr, t_deque *stack[2])
{
	char	*str;

	str = ptr;
	if (!ft_strncmp(str, "sa", 3))
		sa(stack);
	if (!ft_strncmp(str, "sb", 3))
		sb(stack);
	if (!ft_strncmp(str, "ss", 3))
		ss(stack);
	if (!ft_strncmp(str, "pa", 3))
		pa(stack);
	if (!ft_strncmp(str, "pb", 3))
		pb(stack);
	if (!ft_strncmp(str, "ra", 3))
		ra(stack);
	if (!ft_strncmp(str, "rb", 3))
		rb(stack);
	if (!ft_strncmp(str, "rr", 3))
		rr(stack);
	if (!ft_strncmp(str, "rra", 4))
		rra(stack);
	if (!ft_strncmp(str, "rrb", 4))
		rrb(stack);
	if (!ft_strncmp(str, "rrr", 4))
		rrr(stack);
}
