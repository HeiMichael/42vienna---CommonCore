# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miheider <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 11:49:47 by miheider          #+#    #+#              #
#    Updated: 2023/09/23 12:54:37 by miheider         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# M A K E F I L E

CC=cc
CFLAGS=-Wall -Wextra -Werror -g
NAME=libftprintf.a

SRCS=ft_dec_hexa.c ft_integer.c ft_per_char_str.c ft_pointer.c ft_printf.c

SOURCES_DIR:=src
ALL_SOURCES:=ft_printf.c
SOURCES:=$(ALL_SOURCES:%=$(SOURCES_DIR)/%)

OBJS=$(SRCS:.c=.o)

RM=rm -rf 

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean, fclean, re, all

