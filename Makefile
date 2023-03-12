NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS	= -Wall -Werror -Wextra
RM = rm -f
INCLUDES = push_swap.h
INCLUDES_BONUS = bonus/push_swap_bonus.h
SRCS = list_utils.c list_utils2.c operations1.c operations2.c bow_sort.c simple_sort.c radix.c utils.c utils2.c list_management.c
PUSHSWAP_SRCS = push_swap.c $(SRCS)
OBJS = $(PUSHSWAP_SRCS:.c=.o)
SRCS_BONUS = bonus/checker_bonus.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c $(SRCS)
OBJS_BONUS = $(SRCS_BONUS:.c=.o) 

RED = \033[0;31m
GREEN = \033[0;32m

all : $(NAME)
$(NAME): $(OBJS) $(INCLUDES)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[0;32m Push_swap \033[0m"
bonus : $(NAME_BONUS) 
$(NAME_BONUS) : $(OBJS_BONUS) $(INCLUDES_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)
	@echo "\033[0;32m Checker \033[0m"
%.o : %.c
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $(<:.c=.o)
clean :
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@echo "\033[0;31m Object Files Removed. \033[0m"
fclean : clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "\033[0;31m Binaries Removed. \033[0m"
re : fclean all
.PHONY : all clean fclean re
