/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 17:08:32 by yfu               #+#    #+#             */
/*   Updated: 2021/05/04 23:16:42 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_fill(char **line, t_lst *temp)
{
	int		idx[2];
	t_str	*str;

	*line = ft_malloc(((temp->len) - (temp->idx) + 1), sizeof(char));
	if (!(*line))
		return (-1);
	idx[0] = temp->idx;
	idx[1] = 0;
	str = temp->str;
	while (idx[1] < (temp->len) - (temp->idx))
	{
		if (str->s[idx[0]] == '\0')
		{
			str = str->next;
			idx[0] = 0;
		}
		line[0][idx[1]++] = str->s[idx[0]++];
	}
	line[0][idx[1]] = '\0';
	return (ft_clean_lst(temp));
}

static int	ft_end(char **line, t_lst *temp, int res, char *buff)
{
	int	idx[3];

	if (res == 0 && temp->len == 0)
		return (1);
	idx[0] = 0;
	if (res && *buff == '\n' && ft_fill(line, temp) == -1)
		return (-1);
	else if (res && *buff == '\n')
		return (ft_str_add(temp, buff + 1, res - 1));
	while (idx[0] < res && buff[idx[0]] != '\n')
		idx[0]++;
	if (ft_str_add(temp, buff, idx[0]) == -1)
		return (-1);
	if (res != BUFFER_SIZE || idx[0] < res)
	{
		if (ft_fill(line, temp) == -1)
			return (-1);
		if (res == idx[0])
			return (2);
		return (ft_str_add(temp, buff + idx[0] + 1, res - idx[0] - 1));
	}
	return (0);
}

static int	ft_check(t_lst *temp, char **line, t_lst *save)
{
	int	ct[3];

	if (temp->len > temp->idx && temp->str->s[temp->idx] == '\n')
	{
		(temp->idx)++;
		*line = ft_substr("", 0, 0);
		return (1);
	}
	ct[0] = -1;
	ct[1] = 0;
	while (++ct[0] + (temp->idx) < (temp->len))
		if (temp->str->s[ct[0] + temp->idx] == '\n')
			break ;
	if (ct[0] == 0)
		return (ft_clean_lst(temp));
	if (ct[0] + temp->idx < temp->len)
	{
		line[0] = ft_substr(temp->str->s, temp->idx, ct[0]);
		(temp->idx) += ct[0] + 1;
		if (temp->len == temp->idx)
			ft_del_lst(temp, &save, (int *)ct);
		return (1);
	}
	return (0);
}

static void	ft_gnl(int *res, char *buff, char **line, t_lst *temp)
{
	res[0] = read(res[2], buff, BUFFER_SIZE);
	if (res[0] == -1)
	{
		res[1] = -1;
		return ;
	}
	buff[res[0]] = '\0';
	res[1] = ft_end(line, temp, res[0], (char *)buff);
	if (res[1] == 1 || res[1] == 2 || res[0] == 0)
		if (*line == 0)
			*line = ft_substr("", 0, 0);
}

int	get_next_line(int fd, char **line)
{
	char				buff[BUFFER_SIZE + 1];
	static t_lst		*save;
	t_lst				*temp;
	int					res[3];

	temp = save;
	while (temp && temp->fd != fd)
		temp = temp->next;
	if (!temp)
		temp = ft_lst_add(&save, fd);
	if (!temp || fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	*line = 0;
	if (ft_check(temp, line, save))
		return (1);
	res[2] = fd;
	while (1)
	{
		ft_gnl((int *)res, buff, line, temp);
		if (res[0] == -1 || res[1] == -1)
			return (ft_del_lst(temp, &save, (int *)res));
		if (res[1] == 1 || res[1] == 2 || res[0] == 0)
			break ;
	}
	return (ft_del_lst(temp, &save, (int *)res));
}
