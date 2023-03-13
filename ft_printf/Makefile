# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 16:42:18 by sraza             #+#    #+#              #
#    Updated: 2023/02/24 12:31:17 by razasharuku      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_strlen.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putunbr.c \
		ft_putnbr.c \
		ft_printf.c \
		ft_hexa.c \
		ft_pointer.c \
		ft_strptr.c \
		ft_strchr.c 

OBJS = ${SRCS:.c=.o}

all:	$(NAME)

$(NAME):	${OBJS}
		ar -r ${NAME} ${OBJS}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	rm -f ${OBJS}
fclean: clean
	rm -f ${NAME}

re: fclean all
