# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/12 14:21:06 by mcraipea          #+#    #+#              #
#    Updated: 2020/01/28 14:55:59 by pganglof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		minishell

PATH_OBJS_DPDCS = ./objs_dpdcs/
PATH_INIT_PROGRAM = ./srcs/init_program/
PATH_EXEC_COMMAND = ./srcs/exec_command/

SRCS_INIT_PROGRAM =	main.c					\
					garbage_collector.c 	\
					ft_prompt.c 			\
					parsing_command.c

SRCS0 = $(addprefix $(PATH_INIT_PROGRAM), $(SRCS_INIT_PROGRAM))
OBJS0 = $(SRCS0:.c=.o)
# SRCEXT = c
# OBJEXT = o
# SRCS0 = $(shell find $(PATH_INIT_PROGRAM) -type f -name *.$(SRCEXT))
# OBJS0 = $(patsubst $(PATH_INIT_PROGRAM)%,$(PATH_OBJS_DPDCS)%,$(SRCS0:.$(SRCEXT)=.$(OBJEXT)))
HEADERS0 = ./includes/
HEADERS1 = ./libft/includes/
RM = rm -f
LIB = libft/libft.a
CC = gcc
CFLAGS = -g -Ofast -fsanitize=address -Wall -Wextra -Werror -MMD -I $(HEADERS0) -I $(HEADERS1)
DPDCS = $(SRCS0:.c=.d)

-include $(DPDCS)

all: $(NAME)

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