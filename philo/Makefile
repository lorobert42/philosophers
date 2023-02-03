# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 14:40:57 by lorobert          #+#    #+#              #
#    Updated: 2023/02/03 08:35:58 by lorobert         ###   ########.fr        #
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
CFLAGS	:=	-Wall -Wextra -Werror -pthread -fsanitize=address -g

RM		:=	rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all bonus clean fclean re
