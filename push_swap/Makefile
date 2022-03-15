# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcolene <gcolene@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 13:31:05 by gcolene           #+#    #+#              #
#    Updated: 2022/03/15 15:01:54 by gcolene          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 	push_swap

BONUS_NAME		=	checker

SRCS			=	push_swap.c	\
					swaps_a.c	\
					swaps_b.c	\
					swaps_duo.c \
					parser.c 	\
					ft_atoi.c 	\
					sorter.c 	\
					pusher.c 	\
					ft_split.c	\

BONUS_SRCS		=	checker.c				\
					additional_functions.c 	\
					bonus_swaps_a.c			\
					bonus_swaps_b.c			\
					bonus_swaps_duo.c		\
					get_next_line.c			\
					get_next_line_utils.c	\
					bonus_parser.c			\
					bonus_split.c			\

HEADER			= 	push_swap.h

BONUS_HEADER	=	checker.h

OBJS			=	$(SRCS:%.c=%.o)

BONUS_OBJS		= 	$(BONUS_SRCS:%.c=%.o)

CC				=	gcc

CFLAGS			=	-Wall -Werror -Wextra -I$(HEADER)

RM				=	rm -f

all				: 	$(NAME)

$(NAME)			: 	$(OBJS) $(HEADER)
					$(CC) $(OBJS) -o $(NAME)
#
%.o				: 	%.c $(HEADER) $(BONUS_HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_NAME)	:	$(BONUS_OBJS) $(BONUS_HEADER)
					$(CC) $(BONUS_OBJS) -o $(BONUS_NAME)

clean			:
					$(RM) $(OBJS) $(BONUS_OBJS)

fclean			: 	clean
					$(RM) $(NAME) $(BONUS_NAME)
	
re				: 	fclean all

.PHONY			:	all clean fclean re
