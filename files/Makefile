CHECKER = checker

CHECKER_BONUS = checker_bonus

CHECKER_RADIX = checker_radix

CC = cc

CFLAGS = -Wall -Werror -Wextra

INCLUDES_PATH = includes/

INCLUDES = $(INCLUDES_PATH)utils.h

CHECKER_PATH = srcs/checker/

CHECKER_FILES = check.c

CHECKER_MAIN = srcs/checker/main.c

CHECKER_SRCS = $(addprefix $(CHECKER_PATH), $(CHECKER_FILES))

SHARE_PATH = srcs/share/

SHARE_FILES = parse.c	utils.c	operation1.c	operation2.c	operation3.c\
	operation4.c

SHARE_SRCS = $(addprefix $(SHARE_PATH), $(SHARE_FILES))

BONUS_PATH = srcs/bonus/

BONUS_FILES = bonus.c

BONUS_CHECKER_MAIN = srcs/bonus/main.c

BONUS_SRCS = $(addprefix $(BONUS_PATH), $(BONUS_FILES))

RADIX_PATH = srcs/radix/

RADIX_FILES = radix.c

RADIX_CHECKER_MAIN = $(RADIX_PATH)main.c

RADIX_SRCS = $(addprefix $(RADIX_PATH), $(RADIX_FILES))

LIB_PATH = libft/

LIB = $(LIB_PATH)libft.a

CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

CHECKER_MAIN_OBJS = $(CHECKER_MAIN:.c=.o)

BONUS_CHECKER_MAIN_OBJS = $(BONUS_CHECKER_MAIN:.c=.o)

SHARE_OBJS = $(SHARE_SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

RADIX_CHECKER_MAIN_OBJS = $(RADIX_CHECKER_MAIN:.c=.o)

RADIX_OBJS = $(RADIX_SRCS:.c=.o)

all : $(CHECKER)
	@echo "compile OK"

bonus : CFLAGS+=-D\ BONUS=1
bonus : $(CHECKER_BONUS)
	@echo "compile bonus OK"

radix : $(CHECKER_RADIX)
	@echo "compile radix OK"

%.o : %.c $(INCLUDES) $(LIB)
	@$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -c $< -o $@

$(LIB) :
	@$(MAKE) -C $(LIB_PATH)

$(CHECKER) : $(INCLUDES) $(CHECKER_OBJS) $(SHARE_OBJS) $(CHECKER_MAIN_OBJS)
	@$(CC) $(CFLAGS) $(CHECKER_OBJS) $(SHARE_OBJS) $(CHECKER_MAIN_OBJS) $(LIB) -o $(CHECKER)

$(CHECKER_BONUS) : $(INCLUDES) $(CHECKER_OBJS) $(SHARE_OBJS) $(BONUS_OBJS) $(BONUS_CHECKER_MAIN_OBJS)
	@$(CC) $(CFLAGS) $(CHECKER_OBJS) $(SHARE_OBJS) $(BONUS_OBJS) $(BONUS_CHECKER_MAIN_OBJS) $(LIB) -o $(CHECKER_BONUS)

$(CHECKER_RADIX) : $(INCLUDES) $(CHECKER_OBJS) $(SHARE_OBJS) $(RADIX_OBJS) $(RADIX_CHECKER_MAIN_OBJS)
	@$(CC) $(CFLAGS) $(CHECKER_OBJS) $(SHARE_OBJS) $(RADIX_OBJS) $(RADIX_CHECKER_MAIN_OBJS) $(LIB) -o $(CHECKER_RADIX)


clean :
	@rm -rf  $(CHECKER_OBJS) $(SHARE_OBJS) $(CHECKER_MAIN_OBJS)  $(BONUS_CHECKER_MAIN_OBJS) $(BONUS_OBJS) $(RADIX_CHECKER_MAIN_OBJS) $(RADIX_OBJS)
	@$(MAKE) clean -C $(LIB_PATH)
	@echo "clean done"

fclean : clean
	@rm -rf  $(CHECKER) $(CHECKER_BONUS) $(CHECKER_RADIX)
	@$(MAKE) fclean -C $(LIB_PATH)
	@echo "fclean done"

re : fclean all

norm :
	@norminette-old $(SRCS) $(INCLUDES) libft/*.c libft/*.h

.PHONY : all clean fclean re norm debug bonus radix
