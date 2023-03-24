# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 10:38:14 by razasharuku       #+#    #+#              #
#    Updated: 2023/03/19 12:29:49 by razasharuku      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = $(NAME_SERVER) $(NAME_CLIENT)
NAME_SERVER	=	server
NAME_CLIENT	=	client
CFLAGS	=	-Wall -Wextra -Werror
INC		=	-I./libs/libft/ -I./libs/ft_printf/

SRCS_SERVER	=	server.c
SRCS_CLIENT	=	client.c

OBJS_SERVER = ${SRCS_SERVER:%.c=%.o}
OBJS_CLIENT = ${SRCS_CLIENT:%.c=%.o}

all:	$(NAME)

LIBFT		=	./libs/libft/libft.a
FT_PRINTF	=	./libs/ft_printf/libftprintf.a

$(NAME_SERVER):	$(OBJS_SERVER)
	$(MAKE) -C ./libs/libft
	$(MAKE) -C ./libs/ft_printf
	$(CC) $(CFLAGS) $(LIBFT) $(FT_PRINTF) $(SRCS_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT):	$(OBJS_CLIENT)
	$(MAKE) -C ./libs/libft
	$(MAKE) -C ./libs/ft_printf
	$(CC) $(CFLAGS) $(LIBFT) $(FT_PRINTF) $(SRCS_CLIENT) -o $(NAME_CLIENT)

clean:
	$(MAKE) -C ./libs/libft clean
	$(MAKE) -C ./libs/ft_printf clean
	$(RM) $(OBJS_SERVER)
	$(RM) $(OBJS_CLIENT)

fclean:	clean
	$(RM) $(LIBFT)
	$(RM) $(FT_PRINTF)
	$(RM) $(NAME_CLIENT)
	$(RM) $(NAME_SERVER)

re:	fclean all

.PHONY:	all clean fclean re