# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miheider <miheider@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/05 14:51:42 by miheider          #+#    #+#              #
#    Updated: 2024/09/16 12:57:53 by miheider         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# M A K E F I L E

NAME        = animal

SRC         = main.cpp Dog.cpp Cat.cpp Animal.cpp Brain.cpp
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