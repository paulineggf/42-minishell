# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcraipea <mcraipea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/12 14:21:06 by mcraipea          #+#    #+#              #
#    Updated: 2020/01/28 16:49:44 by mcraipea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc

NAME =		minishell

SRC =		main.c \
			garbage_collector.c \
			split_shell.c \
			

OBJ = $(SRC:.c=.o)

CFLAGS = -g -Ofast -fsanitize=address -Wall -Wextra -Werror

all: lib $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $(OBJ) ./libft/libft.a $(CFLAGS)

lib:
	@(cd libft && $(MAKE))

clnlib:
	@(cd libft && $(MAKE) clean)

fclnlib:
	@(cd libft && $(MAKE) fclean)

clean: clnlib
	@/bin/rm -f $(OBJ)

fclean: clean fclnlib
	@/bin/rm -f $(NAME)

re: fclean all