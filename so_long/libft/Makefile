# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/18 20:13:25 by gcolene           #+#    #+#              #
#    Updated: 2022/02/10 16:33:13 by gcolene          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 		libftprintf.a

LIST	=		ft_printf.c\
				ft_print_string.c\
				ft_print_pointer.c\
				ft_print_hex.c\
				ft_print_decimal.c\
				ft_printf_fd.c\
				ft_print_string_fd.c\
				ft_print_pointer_fd.c\
				ft_print_hex_fd.c\
				ft_print_decimal_fd.c\

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