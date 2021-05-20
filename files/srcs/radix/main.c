/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 21:22:47 by yfu               #+#    #+#             */
/*   Updated: 2021/05/21 01:16:03 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		*arr;
	int		arr_size;
	t_list	*instructions;
	char	*line;
	int		fd;
	int		*copy;

	arr_size = get_nbr_in_line(&arr, argc, argv);
	copy = ft_malloc(arr_size, sizeof(int));
	for(int i = 0 ; i < arr_size ; ++i) copy[i] = arr[i];
	ft_sort(copy, copy + arr_size, ft_ascending);
	for(int i = 0 ; i < arr_size ; ++i) arr[i] = binary_search(copy, arr_size, arr[i]);
	instructions = NULL;
	
	fd = open("radix_instructions", O_RDONLY);
	if (fd < 0)
		error_exit();
	while (get_next_line(fd, &line) == 1)
	{
		check_instructions(line);
		ft_lstadd_back(&instructions, ft_lstnew(line));
	}
	if (arr_size == 0)
		normal_exit();
	close(fd);
	check_radix(arr, arr_size, instructions);
	return (0);
}
