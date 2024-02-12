# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 09:47:40 by gchamore          #+#    #+#              #
#    Updated: 2024/02/12 09:47:41 by gchamore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER_NAME = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 -I./includes/

RM = rm -rf

SRCS_SHARE = srcs/utils/mod_libft.c srcs/parsing/parsing_1_arg.c srcs/parsing/parsing.c \
		srcs/instructions/push_function.c srcs/instructions/reverse_rotate_functions.c \
		srcs/instructions/rotate_functions.c srcs/instructions/swap_functions.c \
		srcs/algo/algo_1.c srcs/algo/algo_2.c srcs/algo/algo_3.c \
		srcs/utils/init.c srcs/utils/algo_utils.c srcs/utils/algo_utils_2.c \
		srcs/utils/parsing_utils.c

SRCS_PUSW += $(SRCS_SHARE) srcs/main.c

SRCS_CHECKER += $(SRCS_SHARE) my_checker/checker.c


OBJS_PUSW = $(SRCS_PUSW:.c=.o)
OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)

all: first_header $(NAME) $(CHECKER_NAME) second_header

$(NAME): $(OBJS_PUSW)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o $@ $^ libft/libft.a

$(CHECKER_NAME): $(OBJS_CHECKER)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o $@ $^ libft/libft.a

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS_PUSW) $(OBJS_CHECKER)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) $(CHECKER_NAME)

re: fclean all

.PHONY: all clean fclean re

info: header

first_header:
	@echo "\n $$FIRST_HEADER \n"

define FIRST_HEADER

⠀⠀⠀⠀⠀⠀⠀⠀⠀⡴⠞⠉⢉⣭⣿⣿⠿⣳⣤⠴⠖⠛⣛⣿⣿⡷⠖⣶⣤⡀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣼⠁⢀⣶⢻⡟⠿⠋⣴⠿⢻⣧⡴⠟⠋⠿⠛⠠⠾⢛⣵⣿⠀⠀⠀⠀
⣼⣿⡿⢶⣄⠀⢀⡇⢀⡿⠁⠈⠀⠀⣀⣉⣀⠘⣿⠀⠀⣀⣀⠀⠀⠀⠛⡹⠋⠀⠀⠀⠀
⣭⣤⡈⢑⣼⣻⣿⣧⡌⠁⠀⢀⣴⠟⠋⠉⠉⠛⣿⣴⠟⠋⠙⠻⣦⡰⣞⠁⢀⣤⣦⣤⠀
⠀⠀⣰⢫⣾⠋⣽⠟⠑⠛⢠⡟⠁⠀⠀⠀⠀⠀⠈⢻⡄⠀⠀⠀⠘⣷⡈⠻⣍⠤⢤⣌⣀
⢀⡞⣡⡌⠁⠀⠀⠀⠀⢀⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⢿⡀⠀⠀⠀⠸⣇⠀⢾⣷⢤⣬⣉
⡞⣼⣿⣤⣄⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⣿⠀⠸⣿⣇⠈⠻
⢰⣿⡿⢹⠃⠀⣠⠤⠶⣼⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⣿⠀⠀⣿⠛⡄⠀
⠈⠉⠁⠀⠀⠀⡟⡀⠀⠈⡗⠲⠶⠦⢤⣤⣤⣄⣀⣀⣸⣧⣤⣤⠤⠤⣿⣀⡀⠉⣼⡇⠀
⣿⣴⣴⡆⠀⠀⠻⣄⠀⠀⠡⠀⠀⠀⠈⠛⠋⠀⠀⠀⡈⠀⠻⠟⠀⢀⠋⠉⠙⢷⡿⡇⠀
⣻⡿⠏⠁⠀⠀⢠⡟⠀⠀⠀⠣⡀⠀⠀⠀⠀⠀⢀⣄⠀⠀⠀⠀⢀⠈⠀⢀⣀⡾⣴⠃⠀
⢿⠛⠀⠀⠀⠀⢸⠁⠀⠀⠀⠀⠈⠢⠄⣀⠠⠼⣁⠀⡱⠤⠤⠐⠁⠀⠀⣸⠋⢻⡟⠀⠀
⠈⢧⣀⣤⣶⡄⠘⣆⠀⠀⠀⠀⠀⠀⠀⢀⣤⠖⠛⠻⣄⠀⠀⠀⢀⣠⡾⠋⢀⡞⠀⠀⠀
⠀⠀⠻⣿⣿⡇⠀⠈⠓⢦⣤⣤⣤⡤⠞⠉⠀⠀⠀⠀⠈⠛⠒⠚⢩⡅⣠⡴⠋⠀⠀⠀⠀
⠀⠀⠀⠈⠻⢧⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⣻⠿⠋⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠉⠓⠶⣤⣄⣀⡀⠀⠀⠀⠀⠀⢀⣀⣠⡴⠖⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀

endef
export FIRST_HEADER

second_header:
	@echo "\n$$SECOND_HEADER \n"

define SECOND_HEADER
██████████████████████████████████████████████████████████████████████
█▌                                                                  ▐█
█▌                                                                  ▐█
█▌  ██╗  ██╗██████╗     ██████╗  ██████╗ ██████╗ ███╗   ██╗         ▐█
█▌  ██║  ██║╚════██╗    ██╔══██╗██╔═══██╗██╔══██╗████╗  ██║         ▐█
█▌  ███████║ █████╔╝    ██████╔╝██║   ██║██████╔╝██╔██╗ ██║         ▐█
█▌  ╚════██║██╔═══╝     ██╔══██╗██║   ██║██╔══██╗██║╚██╗██║         ▐█
█▌       ██║███████╗    ██████╔╝╚██████╔╝██║  ██║██║ ╚████║         ▐█
█▌       ╚═╝╚══════╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝         ▐█
█▌                                                                  ▐█
█▌  ████████╗ ██████╗      ██████╗ ██████╗ ██████╗ ███████╗    ██╗  ▐█
█▌  ╚══██╔══╝██╔═══██╗    ██╔════╝██╔═══██╗██╔══██╗██╔════╝    ██║  ▐█
█▌     ██║   ██║   ██║    ██║     ██║   ██║██║  ██║█████╗      ██║  ▐█
█▌     ██║   ██║   ██║    ██║     ██║   ██║██║  ██║██╔══╝      ╚═╝  ▐█
█▌     ██║   ╚██████╔╝    ╚██████╗╚██████╔╝██████╔╝███████╗    ██╗  ▐█
█▌     ╚═╝    ╚═════╝      ╚═════╝ ╚═════╝ ╚═════╝ ╚══════╝    ╚═╝  ▐█
█▌                                                                  ▐█
█▌                                                                  ▐█
█▌                                                                  ▐█
██████████████████████████████████████████████████████████████████████
endef
export SECOND_HEADER

header:
	@echo "$$FIRST_HEADER"
	@echo "$$SECOND_HEADER"
