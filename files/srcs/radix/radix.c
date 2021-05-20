/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 19:57:16 by yfu               #+#    #+#             */
/*   Updated: 2021/05/21 00:47:26 by yfu              ###   ########lyon.fr   */
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
			display_stack_radix(stack, last_operation);
			assigned_operation(cur_instruction->content, stack);
			display_stack_radix(stack, (char *)(cur_instruction->content));
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

void	check_radix(int *arr, int arr_size, t_list *instructions)
{
	t_list			*cur_instruction;
	t_deque			*stack[2];
	void			*last_operation;
	extern int		g_size;

	stack[0] = deque_init();
	stack[1] = deque_init();
	if (!stack[0] || !stack[1])
		error_exit();
	init_stack(stack[0], arr, arr_size);
	cur_instruction = instructions;
	last_operation = "Init a and b";
	clearscreen();
	g_size = 0;
	while (((arr_size - 1)>>g_size) > 0)
		++g_size;
	display_stack_radix(stack, last_operation);
	ft_putendl_fd("press enter to continue", 1);
	sub(cur_instruction, stack, last_operation);
	ok(instructions);
}

static void	display_number_width11_base2(int num)
{
	extern int	g_size;

	for(int i = 0 ; i + g_size < 11 ; ++i) ft_putchar_fd(' ', 1);
	for (int i = g_size - 1 ; i >= 0 ; --i)
	{
		ft_putchar_fd(((num>>i)&1) + '0', 1);
	}
}

static void	sub2(int ct[3], t_double_list *cur[2],
char *message, t_deque *stack[2])
{
	ct[0] = ft_max(stack[0]->size, stack[1]->size);
	ct[2] = stack[0]->size + stack[1]->size - ct[0];
	ft_putendl_fd(message, 1);
	while (ct[2]-- > 0)
		ft_putendl_fd("", 1);
	cur[0] = stack[0]->tail;
	cur[1] = stack[1]->tail;
}

void	display_stack_radix(t_deque *stack[2], char *message)
{
	int				ct[3];
	t_double_list	*cur[2];

	sub2(ct, cur, message, stack);
	while (--ct[0] >= 0)
	{
		if (ct[0] < stack[0]->size)
		{
			display_number_width11_base2(*((int *)cur[0]->content));
			cur[0] = cur[0]->last;
		}
		else
			ft_putstr_fd("           ", 1);
		ft_putstr_fd("     ", 1);
		if (ct[0] < stack[1]->size)
		{
			display_number_width11_base2(*((int *)cur[1]->content));
			cur[1] = cur[1]->last;
		}
		ft_putendl_fd("", 1);
	}
	ft_putendl_fd("__________a     __________b", 1);
	ft_putendl_fd("---------------------------", 1);
}
