/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:09:14 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 23:16:49 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_str
{
	char			*s;
	struct s_str	*next;
}				t_str;

typedef struct s_lst
{
	t_str			*str;
	int				len;
	int				fd;
	int				idx;
	struct s_lst	*next;
}				t_lst;

int				get_next_line(int fd, char **line);
t_lst			*ft_lst_add(t_lst **dst, int fd);
int				ft_str_add(t_lst *dst, char *s, int len);
int				ft_clean_lst(t_lst *lst);
int				ft_del_lst(t_lst *target, t_lst **head, int *res);

#endif
