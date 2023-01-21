# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 14:40:57 by lorobert          #+#    #+#              #
#    Updated: 2023/01/20 08:33:49 by lorobert         ###   ########.fr        #
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
			supervisor.c
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
