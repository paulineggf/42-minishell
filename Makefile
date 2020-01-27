# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/12 14:21:06 by mcraipea          #+#    #+#              #
#    Updated: 2020/01/27 18:27:14 by pganglof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc

NAME =		minishell

SRC =		main.c				\
			garbage_collector.c \
			ft_prompt.c 		\
			parsing_command.c

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