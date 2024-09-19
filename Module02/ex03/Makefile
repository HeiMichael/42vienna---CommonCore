# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miheider <miheider@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 15:27:24 by miheider          #+#    #+#              #
#    Updated: 2024/09/10 11:56:59 by miheider         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# M A K E F I L E

NAME        = bsp

SRC         = main.cpp Fixed.cpp Point.cpp bsp.cpp
CC          = c++
CPPFLAGS    = -Wall -Wextra -Werror -std=c++98 -pedantic
RM          = rm -rf
OBJ         = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re