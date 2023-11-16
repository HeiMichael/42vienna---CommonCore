# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miheider <miheider@42>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 17:18:38 by miheider          #+#    #+#              #
#    Updated: 2023/11/16 16:52:04 by miheider         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# M A K F I L E

NAME=fractol

SRCS=calculate.c connection.c events.c fractol.c julia.c mandelbrot.c \
	 rendering.c

#B_SRCS=

OBJS=$(SRCS:.c=.o)
B_OBJS=$(B_SRCS:.c=.o)

CC=cc
CFLAGS=-Wall -Wextra -Werror -g -lmlx -lXext -lX11
RM=rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) -r $@ $?

bonus: $(OBJS) $(B_OBJS)
	$(AR) -r $(NAME) $?

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean, fclean, re, bonus
