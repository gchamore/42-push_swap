NAME = lib_swap.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -I./includes/

RM = rm -rf

SRCS = srcs/ft_print_piles.c srcs/mod_libft.c srcs/parsing_1_arg.c srcs/parsing.c \
		srcs/push_function.c srcs/reverse_rotate_functions.c srcs/rotate_functions.c \
		srcs/swap_functions.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

info: header
