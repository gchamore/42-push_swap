NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 -I./includes/

RM = rm -rf

SRCS = 	srcs/utils/mod_libft.c srcs/parsing/parsing_1_arg.c srcs/parsing/parsing.c \
		srcs/instructions/push_function.c srcs/instructions/reverse_rotate_functions.c srcs/instructions/rotate_functions.c \
		srcs/instructions/swap_functions.c srcs/algo/algo.c srcs/main.c srcs/utils/init.c srcs/utils/algo_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o $@ $^ libft/libft.a
	$(RM) $(OBJS)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

info: header
