# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pganglof <pganglof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 12:22:08 by pganglof          #+#    #+#              #
#    Updated: 2019/11/07 14:47:12 by pganglof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PATH = ./srcs/
PRINTF_PATH = ./srcs/printf/

SRCS_NAME =		ft_strlen.c			\
				ft_strlcat.c		\
				ft_strlcpy.c		\
				ft_putchar_fd.c		\
				ft_putstr_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				ft_bzero.c			\
				ft_memset.c			\
				ft_memmove.c		\
				ft_memcpy.c			\
				ft_memccpy.c		\
				ft_memchr.c			\
				ft_calloc.c			\
				ft_strchr.c			\
				ft_strrchr.c		\
				ft_strmapi.c		\
				ft_substr.c			\
				ft_strjoin.c		\
				ft_strnjoin.c		\
				ft_strtrim.c		\
				ft_strupcase.c		\
				ft_split.c			\
				ft_strnstr.c		\
				ft_itoa.c			\
				ft_uitoa.c			\
				ft_strdup.c			\
				ft_strncmp.c		\
				ft_isalpha.c		\
				ft_isdigit.c		\
				ft_isalnum.c		\
				ft_isascii.c		\
				ft_isprint.c		\
				ft_toupper.c		\
				ft_tolower.c		\
				ft_atoi.c			\
				ft_memcmp.c			\
				ft_strequ.c			\
				ft_lstsize.c		\
				ft_strnlen.c		\
				ft_strdel.c			\
				ft_lstnew.c			\
				ft_putnbr.c			\
				ft_lstlast.c		\
				ft_lstmap.c			\
				ft_lstclear.c		\
				ft_lstdelone.c		\
				ft_putendl.c		\
				ft_isspace.c		\
				ft_charset.c		\
				ft_isupper.c		\
				ft_islower.c		\
				ft_strndup.c		\
				ft_putstr.c			\
				ft_strcmp.c			\
				ft_strcat.c			\
				ft_strstr.c			\
				ft_strncat.c		\
				ft_strmap.c			\
				ft_putchar.c		\
				ft_lstadd_front.c	\
				ft_lstadd_back.c	\
				ft_strcpy.c			\
				ft_strncpy.c		\
				ft_memrchr.c		\
				ft_lstiter.c		\
				get_next_line.c

NAME_PRINTF =	ft_printf.c							\
				flag_c/fct_c.c 						\
				flag_c/c_check_wildcard.c 			\
				flag_c/c_chaine_vide.c				\
				flag_c/c_tiret.c 					\
				flag_c/c_nbr.c 						\
				flag_id/fct_id.c 					\
				flag_id/id_zero_point.c				\
				flag_id/id_nbr.c					\
				flag_id/id_point.c					\
				flag_id/id_tiret.c					\
				flag_id/id_zero.c					\
				flag_id/id_tiret_point.c 			\
				flag_id/id_nbr_point.c 				\
				flag_id/id_check_wildcard.c 		\
				flag_id/id_chaine_vide.c 			\
				flag_p/fct_p.c 						\
				flag_p/p_check_wildcard.c 			\
				flag_p/p_tiret.c 					\
				flag_p/p_nbr.c 						\
				flag_p/p_0x.c 						\
				flag_s/fct_s.c 						\
				flag_s/s_tiret.c 					\
				flag_s/s_nbr.c 						\
				flag_s/s_free.c 					\
				flag_s/s_tiret_point.c 				\
				flag_s/s_nbr_point.c 				\
				flag_s/s_check_wildcard.c 			\
				flag_s/s_chaine_vide.c				\
				flag_u/fct_u.c 						\
				flag_u/u_zero_point.c				\
				flag_u/u_nbr.c						\
				flag_u/u_point.c					\
				flag_u/u_tiret.c					\
				flag_u/u_zero.c						\
				flag_u/u_tiret_point.c 				\
				flag_u/u_nbr_point.c 				\
				flag_u/u_check_wildcard.c 			\
				flag_u/u_chaine_vide.c 				\
				flag_x/fct_x.c						\
				flag_x/x_point.c 					\
				flag_x/x_tiret.c 					\
				flag_x/x_nbr.c 						\
				flag_x/x_zero.c 					\
				flag_x/x_nbr_point.c 				\
				flag_x/x_tiret_point.c 				\
				flag_x/x_zero_point.c 				\
				flag_x/x_chaine_vide.c				\
				flag_x/x_check_wildcard.c  			\
				flag_%/fct_pourcentage.c 			\
				flag_%/pourc_check_wildcard.c	 	\
				flag_%/pourc_tiret.c 				\
				flag_%/pourc_nbr.c 					\
				flag_%/pourc_zero.c 				\
				convert_hex.c						\
				recup_flags/match_type.c			\
				recup_flags/init_ptrf.c 			\
				recup_flags/init_lst.c				\
				recup_flags/ft_atoi_printf.c		

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
SRCS_PRINTF = $(addprefix $(PRINTF_PATH), $(NAME_PRINTF))
HEADERS = ./includes/
OBJS = $(SRCS:.c=.o)
OBJS_PRINTF = $(SRCS_PRINTF:.c=.o)
NAME = libft.a
RM = rm -f
AR = ar
AFLAGS = -sucr
CFLAGS += -Wall -Wextra -Werror -I $(HEADERS)

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_PRINTF)
	$(AR) $(AFLAGS) $(NAME) $(OBJS) $(OBJS_PRINTF)

clean:
	$(RM) $(OBJS) $(OBJS_PRINTF)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all
.PHONY: all clean fclean re
