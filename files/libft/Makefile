# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfu <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/12 12:17:32 by yfu               #+#    #+#              #
#    Updated: 2021/03/12 15:58:31 by yfu              ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS = ft_split.c	ft_strchr.c \
ft_atoi.c	ft_strdup.c \
ft_bzero.c			ft_strjoin.c \
ft_calloc.c			ft_memccpy.c		ft_strlcat.c \
ft_isalnum.c		ft_memchr.c			ft_strlcpy.c \
ft_isalpha.c		ft_memcmp.c			ft_strlen.c \
ft_isascii.c		ft_memcpy.c			ft_strmapi.c \
ft_isdigit.c		ft_memmove.c		ft_strncmp.c \
ft_isprint.c		ft_memset.c			ft_strnstr.c \
ft_itoa.c			ft_strrchr.c \
ft_putchar_fd.c		ft_strtrim.c \
ft_putendl_fd.c		ft_substr.c \
ft_putnbr_fd.c		ft_tolower.c \
ft_putstr_fd.c		ft_toupper.c

BONUS_SRCS = ft_lstadd_back.c	ft_lstadd_front.c\
ft_lstclear.c	ft_lstdelone.c	ft_lstiter.c \
ft_lstlast.c	ft_lstmap.c		ft_lstnew.c\
ft_lstsize.c	ft_memory.c	ft_memory_utils.c	ft_lstfind.c\
get_next_line.c	get_next_line_utils.c	get_next_line_sub.c	ft_minmax.c	ft_isspace.c\
deque.c	deque_utils.c	ft_sort.c	binary_search.c	ft_sqrt.c

HEADER = libft.h	get_next_line.h

OBJECTS = $(SRCS:.c=.o)

BONUS_OBJECTS = $(BONUS_SRCS:.c=.o)

all : $(NAME)

bonus : $(OBJECTS) $(BONUS_OBJECTS)
	@ar rc $(NAME) $(OBJECTS) $(BONUS_OBJECTS)
	@ranlib $(NAME)
	@echo "libft.a created / updated"

$(NAME): $(HEADER) $(OBJECTS) $(BONUS_OBJECTS)
	@ar rc $(NAME) $(OBJECTS) $(BONUS_OBJECTS)
	@ranlib $(NAME)
	@echo "libft.a created / updated"

%.o : %.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
		@rm -rf $(OBJECTS) $(BONUS_OBJECTS)
		@echo "libft.a clean done"

fclean: 
		@rm -rf $(OBJECTS) $(BONUS_OBJECTS)
		@rm -rf $(NAME)
		@echo "libft.a fclean done"

re: fclean all

norm :
	norminette $(shell find *.c *.h)

.PHONY : all bonus clean fclean re
