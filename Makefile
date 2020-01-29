# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/12 14:21:06 by mcraipea          #+#    #+#              #
#    Updated: 2020/01/29 19:08:56 by pganglof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PATH_INIT_PROGRAM = ./srcs/init_program/
#PATH_EXEC_COMMAND = ./srcs/exec_command/

SRCS_INIT_PROGRAM =	main.c					\
					garbage_collector.c 	\
					ft_prompt.c 			\
					parsing_command.c 		\
					split_shell.c

SRCS0 = $(addprefix $(PATH_INIT_PROGRAM), $(SRCS_INIT_PROGRAM))
HEADERS0 = ./includes/
HEADERS1 = ./libft/includes/
OBJS0 = $(SRCS0:.c=.o)
NAME =	minishell
LIB = libft/libft.a
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g -MMD -I $(HEADERS0) -I $(HEADERS1) -Ofast
DPDCS = $(SRCS0:.c=.d)

all: $(NAME)

-include $(DPDCS)

$(NAME): $(OBJS0) $(LIB)
	$(CC) $(CFLAGS) $(OBJS0) -o $(NAME) $(LIB)

$(LIB):
	cd ./libft/ && make && cd ..

clean:
	$(RM) $(OBJS0) $(LIB) -include $(DPDCS)
	cd ./libft/ && make fclean && cd ..

fclean: clean
	$(RM) $(NAME)
	
re: fclean all
.PHONY: all clean fclean re