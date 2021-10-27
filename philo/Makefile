# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlinkov <rlinkov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 17:09:16 by rlinkov           #+#    #+#              #
#    Updated: 2021/09/17 15:15:36 by rlinkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= philo

CC 			:=	gcc
CFLAGS	 	:=	-Wall -Wextra -Werror -pthread
RM 			:=	/bin/rm -f

INCLUDE 	:= 	-Iinclude/

SRCS		:=	src/main.c \
				src/inputs.c \
				src/init.c \
				src/error.c \
				src/utils.c \
				src/action.c \
				src/status.c \
				src/print.c \

OBJ			:=	$(SRCS:%.c=%.o)

all			:	$(NAME)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

$(NAME)		:	$(OBJ)
	@ $(CC) $(CFLAGS) $(INCLUDE) $(SRCS) -o $(NAME)

clean		:
	@ $(RM) $(OBJ)

fclean		:	clean
	@ $(RM) philo

re			: fclean all

.PHONY		: all clean fclean remake
