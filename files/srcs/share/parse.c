/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:20:00 by yfu               #+#    #+#             */
/*   Updated: 2021/05/05 00:02:17 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	put_in_list(t_list **lst, char *str)
{
	int	*temp;

	while (*str)
	{
		if (ft_isspace(*str))
			str++;
		else if (ft_isdigit(*str) || *str == '-' || *str == '+')
		{
			temp = ft_malloc(1, sizeof(int *));
			if (!temp)
				error_exit();
			*temp = ft_atoi_with_range(&str);
			ft_lstadd_back(lst, ft_lstnew((void *)temp));
		}
		else
			error_exit();
	}
}

int	has_duplicate(int *arr, int arrsize)
{
	int	ct[2];

	ct[0] = -1;
	while (++ct[0] < arrsize - 1)
	{
		ct[1] = ct[0];
		while (++ct[1] < arrsize)
		{
			if (arr[ct[0]] == arr[ct[1]])
				return (1);
		}
	}
	return (0);
}

int	get_nbr_in_line(int **arr, int argc, char **argv)
{
	t_list	*lst;
	int		ct;

	lst = NULL;
	if (argc == 1)
		return (0);
	ct = 0;
	while (++ct < argc)
		put_in_list(&lst, argv[ct]);
	*arr = ft_malloc(ft_lstsize(lst), sizeof(int));
	if (!(*arr))
		error_exit();
	ct = 0;
	while (lst)
	{
		arr[0][ct++] = *((int *)(lst->content));
		lst = lst->next;
	}
	if (has_duplicate(arr[0], ct))
		error_exit();
	return (ct);
}

void	check_instructions(char *str)
{
	if (!ft_strncmp(str, "sa", 3))
		return ;
	if (!ft_strncmp(str, "sb", 3))
		return ;
	if (!ft_strncmp(str, "ss", 3))
		return ;
	if (!ft_strncmp(str, "pa", 3))
		return ;
	if (!ft_strncmp(str, "pb", 3))
		return ;
	if (!ft_strncmp(str, "ra", 3))
		return ;
	if (!ft_strncmp(str, "rb", 3))
		return ;
	if (!ft_strncmp(str, "rr", 3))
		return ;
	if (!ft_strncmp(str, "rra", 4))
		return ;
	if (!ft_strncmp(str, "rrb", 4))
		return ;
	if (!ft_strncmp(str, "rrr", 4))
		return ;
	error_exit();
}
