/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 19:57:16 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 23:43:14 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <fcntl.h>

static void	clearscreen(void)
{
	write(1, "\e[1;1H\e[2J", 11);
}

static void	ko(void)
{
	ft_putendl_fd("\033[0;31mKO\033[0m", 1);
	exit(EXIT_SUCCESS);
}

static void	ok(t_list *instructions)
{
	ft_putstr_fd("\033[1;32mOK with ", 1);
	ft_putnbr_fd(ft_lstsize(instructions), 1);
	ft_putendl_fd(" operations\033[0m", 1);
	exit(EXIT_SUCCESS);
}

static void	sub(t_list *cur_instruction, t_deque *stack[2],
void *last_operation)
{
	char			c;
	t_double_list	*cur;

	while (cur_instruction)
	{
		read(0, &c, 1);
		if (c == '\n')
		{
			clearscreen();
			display_stacks(stack, last_operation);
			assigned_operation(cur_instruction->content, stack);
			display_stacks(stack, (char *)(cur_instruction->content));
			last_operation = cur_instruction->content;
			cur_instruction = cur_instruction->next;
		}
	}
	if (stack[1]->size)
		ko();
	cur = stack[0]->head;
	while (cur->next)
	{
		if (*((int *)cur->content) < *((int *)cur->next->content))
			ko();
		cur = cur->next;
	}
}

void	check_bonus(int *arr, int arr_size, t_list *instructions)
{
	t_list			*cur_instruction;
	t_deque			*stack[2];
	void			*last_operation;

	stack[0] = deque_init();
	stack[1] = deque_init();
	if (!stack[0] || !stack[1])
		error_exit();
	init_stack(stack[0], arr, arr_size);
	cur_instruction = instructions;
	last_operation = "Init a and b";
	clearscreen();
	display_stacks(stack, last_operation);
	ft_putendl_fd("press enter to continue", 1);
	sub(cur_instruction, stack, last_operation);
	ok(instructions);
}
