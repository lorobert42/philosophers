# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 14:40:57 by lorobert          #+#    #+#              #
#    Updated: 2023/02/01 12:37:52 by lorobert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	philo

SRCS	:=	philo.c \
			ft_print.c \
			ft_atoi.c \
			time.c \
			philosophy.c \
			eat.c \
			sleep.c \
			end.c \
			supervisor.c \
			init.c \
			min.c \
			clean.c
OBJS	:=	$(SRCS:.c=.o)

CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror -pthread -g

RM		:=	rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -pthread

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all bonus clean fclean re
