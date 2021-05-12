/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:16:31 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 18:45:36 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	main(int argc, char **argv)
{
	int		*arr;
	int		arr_size;
	t_list	*instructions;
	char	*line;

	arr_size = get_nbr_in_line(&arr, argc, argv);
	if (arr_size == 0)
		normal_exit();
	instructions = NULL;
	while (get_next_line(0, &line) == 1)
	{
		check_instructions(line);
		ft_lstadd_back(&instructions, ft_lstnew(line));
	}
	if (arr_size == 0)
		normal_exit();
	else if (check(arr, arr_size, instructions))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_free_all();
	return (0);
}
