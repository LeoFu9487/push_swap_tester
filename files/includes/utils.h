/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:23:05 by yfu               #+#    #+#             */
/*   Updated: 2021/05/21 00:26:39 by yfu              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# ifndef DEBUG
#  define DEBUG 0
# endif
# ifndef BONUS
#  define BONUS 0
# endif
# ifndef RADIX
#  define RADIX 0
# endif
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

int				g_size;
void			normal_exit(void);
void			error_exit(void);
int				get_nbr_in_line(int **arr, int argc, char **argv);
int				ft_atoi_with_range(char **str);
int				has_duplicate(int *arr, int arrsize);
void			check_instructions(char *str);
int				check(int *arr, int arr_size, t_list *instructions);
void			check_bonus(int *arr, int arr_size, t_list *instructions);
void			sa(t_deque *stack[2]);
void			sb(t_deque *stack[2]);
void			ss(t_deque *stack[2]);
void			pa(t_deque *stack[2]);
void			pb(t_deque *stack[2]);
void			ra(t_deque *stack[2]);
void			rb(t_deque *stack[2]);
void			rr(t_deque *stack[2]);
void			rra(t_deque *stack[2]);
void			rrb(t_deque *stack[2]);
void			rrr(t_deque *stack[2]);
void			display_stacks(t_deque *stack[2], char *message);
void			init_stack(t_deque *stack, int *arr, int arr_size);
void			assigned_operation(void *ptr, t_deque *stack[2]);
t_deque			*push_swap(t_deque *stack[2]);
void			display_instructions(t_deque *ins, int *arr, int size, int fd);
void			descretize_stack(t_deque *stack, int *arr, int arr_size);
int				check_order(t_deque *stack[2]);
void			generate_instructions(t_deque *st[2], char *str, t_deque *ins);
void			easy_solve(t_deque *stack[2], t_deque *instructions);
void			medium_solve(t_deque *stack[2], t_deque *instructions);
void			hard_solve(t_deque *stack[2], t_deque *instructions);
void			check_radix(int *arr, int arr_size, t_list *instructions);
void			display_stack_radix(t_deque *stack[2], char *message);


#endif
