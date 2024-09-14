# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miheider <miheider@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 10:43:56 by miheider          #+#    #+#              #
#    Updated: 2024/09/10 14:50:13 by miheider         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= claptrap 

SRC			= main.cpp ClapTrap.cpp
CC			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic
RM			= rm -rf
OBJ 		= $(SRC:.cpp=.o)

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