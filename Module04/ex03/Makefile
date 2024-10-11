# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miheider <miheider@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/05 14:51:42 by miheider          #+#    #+#              #
#    Updated: 2024/09/25 09:04:17 by miheider         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# M A K E F I L E

NAME        = materia

SRC         = main.cpp MateriaSource.cpp Ice.cpp Cure.cpp Character.cpp AMateria.cpp
CC          = c++
CPPFLAGS    = -Wall -Wextra -Werror -std=c++98 -pedantic -g
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