# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorobert <lorobert@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 14:40:57 by lorobert          #+#    #+#              #
#    Updated: 2022/12/07 15:23:20 by lorobert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	philo

SRCS	:=	philo.c \
			ft_atoi.c
OBJS	:=	$(SRCS:.c=.o)

LIBS	:=	
LIBS_TARGET	:=	

INCS	:=	

CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror
CPPFLAGS	:=	$(addprefix -I, $(INCS)) -MMD -MP
LDFLAGS	:=	$(addprefix -L, $(dir $(LIBS_TARGET)))
LDLIBS	:=	$(addprefix -l, $(LIBS))

RM		:=	rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

$(LIBS_TARGET):
	make bonus -C $(@D)

clean:
	for f in $(dir $(LIBS_TARGET)); do make -C $$f clean; done
	$(RM) $(OBJS)

fclean: clean
	for f in $(dir $(LIBS_TARGET)); do make -C $$f fclean; done
	$(RM) $(NAME)

re:	fclean all

.PHONY: all bonus clean fclean re
