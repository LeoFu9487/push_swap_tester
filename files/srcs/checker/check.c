/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:16:15 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 23:46:21 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** arr_size >= 2
** tail means top
** head means bottom
*/

static void	sub(t_list *cur_instruction, t_deque *stack[2])
{
	while (cur_instruction)
	{
		assigned_operation(cur_instruction->content, stack);
		if (DEBUG == 1)
			display_stacks(stack, (char *)(cur_instruction->content));
		cur_instruction = cur_instruction->next;
	}
}

int	check(int *arr, int arr_size, t_list *instructions)
{
	t_deque			*stack[2];
	t_double_list	*cur;

	stack[0] = deque_init();
	stack[1] = deque_init();
	if (!stack[0] || !stack[1])
		error_exit();
	init_stack(stack[0], arr, arr_size);
	if (DEBUG == 1)
		display_stacks(stack, "Init a and b");
	sub(instructions, stack);
	if (stack[1]->size)
		return (0);
	cur = stack[0]->head;
	while (cur->next)
	{
		if (*((int *)cur->content) < *((int *)cur->next->content))
			return (0);
		cur = cur->next;
	}
	return (1);
}
