# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 16:42:57 by gcolene           #+#    #+#              #
#    Updated: 2022/02/16 17:21:01 by gcolene          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	so_long
GCC			=	cc
LIBFT		=	./libft/libftprintf.a 
LIB_BINARY	=	-L '.' -lft 
CFLAGS		=	-Wall -Werror -Wextra

SRCS		=	so_long.c \
				ft_check_map_file.c \
				ft_exit_function.c \
  				ft_hooks.c \
				ft_read_map_file.c \
				ft_screen_creation.c \
				ft_sprites_load.c \


OBJS		=	$(SRCS:.c=.o)

RM			=	rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) -lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) ./libftprintf.a ./libft.a

$(LIBFT):
	make -C ./libft/
	cp ./libft/MyLibft/libft.a ./libft.a
	cp ./libft/libftprintf.a ./libftprintf.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C ./mlx/ clean
	make -C ./libft/ clean

fclean: clean
	$(RM) $(NAME)
	make -C ./libft/ fclean
	rm ./libftprintf.a
	rm ./libft.a
	
re: fclean all

.PHONY:	all clean fclean re
