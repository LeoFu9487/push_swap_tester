/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:16:29 by yfu               #+#    #+#             */
/*   Updated: 2021/05/05 00:10:28 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	sub(long long ct[3], char **str)
{
	ct[0] = -1LL;
	if (str[0][0] == '+' || str[0][0] == '-')
		ct[0] = 0LL;
	ct[2] = 1LL;
	if (str[0][0] == '-')
		ct[2] = -1LL;
	ct[1] = 0LL;
	if ((str[0][0] == '-' || str[0][0] == '+') && !ft_isdigit(str[0][1]))
		error_exit();
}

int	ft_atoi_with_range(char **str)
{
	long long int	ct[3];

	sub(ct, str);
	while (str[0][++ct[0]])
	{
		if (!ft_isdigit(str[0][ct[0]]))
		{
			*str += ct[0];
			if (ft_isspace(str[0][0]))
				return (ct[1] * ct[2]);
			error_exit();
		}
		ct[1] = 10LL * ct[1] + str[0][ct[0]] - '0';
		if ((ct[2] == 1LL && ct[1] > 2147483647LL) || (ct[2] == -1LL && ct[1]
				> 2147483648LL) || (ct[1] == 0LL
				&& ft_isdigit(str[0][ct[0] + 1])))
			error_exit();
	}
	*str += ct[0];
	return (ct[1] * ct[2]);
}

void	error_exit(void)
{
	ft_putendl_fd("Error", 2);
	ft_free_all();
	exit(EXIT_FAILURE);
}

void	normal_exit(void)
{
	ft_free_all();
	exit(EXIT_SUCCESS);
}
