# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/18 20:13:25 by gcolene           #+#    #+#              #
#    Updated: 2021/11/25 16:56:15 by gcolene          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 		libftprintf.a

LIST	=		ft_printf.c\
				ft_print_string.c\
				ft_print_pointer.c\
				ft_print_hex.c\
				ft_print_decimal.c\

HEADER	= 		ft_printf.h

OBJ		=		$(LIST:%.c=%.o)

CC		=		gcc

CFLAGS	=		-Wall -Wextra -Werror -I$(HEADER)

LIBFT 	= 		MyLibft/libft.a

.PHONY	=		all clean fclean re

all		:		$(NAME)

$(NAME)	:		$(OBJ) $(HEADER)
				$(MAKE) -C ./MyLibft
				cp $(LIBFT) $(NAME)
				ar rc $(NAME) $(OBJ) $?
				ranlib $(NAME)

%.o		:		%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

clean	:
				$(MAKE) clean -C ./MyLibft
				rm -f $(OBJ)

fclean	:		clean
				$(MAKE) fclean -C ./MyLibft
				$(RM) $(NAME)

re		:		fclean all