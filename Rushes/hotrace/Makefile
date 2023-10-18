# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miheider <miheider@42>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 23:11:05 by miheider          #+#    #+#              #
#    Updated: 2023/10/17 11:05:36 by miheider         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# M A K E F I L E

NAME = hotrace
CC = cc
CFLAGS = -Werror -Wextra -Wall -O3
RM = rm -rf

SRC = \
	get_next_line.c \
	helpers.c \
	hotrace.c \
	print_result.c \
	vla_hash.c \
	vla.c
HEADER = hotrace.h

OBJ=$(SRC:.c=.o)

all: $(NAME)

run: $(NAME)
	./$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $? -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re run
