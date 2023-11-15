# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miheider <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 17:18:38 by miheider          #+#    #+#              #
#    Updated: 2023/11/09 16:08:31 by miheider         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# M A K F I L E

NAME=

SRCS=

B_SRCS=

OBJS=$(SRCS:.c=.o)
B_OBJS=$(B_SRCS:.c=.o)

CC=cc
CFLAGS=-Wall -Wextra -Werror -g
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
