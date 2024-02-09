# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miheider <miheider@42>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 17:18:38 by miheider          #+#    #+#              #
#    Updated: 2024/01/21 21:09:55 by miheider         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# M A K E F I L E

CC     = cc
AR     = ar rcs
CFLAGS = -Wall -Wextra -Werror
NAME   = libunit.a
CFILES = libunit.c start.c tests/strlen/00_launcher.c tests/strlen/01_basictest.c \
	   tests/strlen/02_nulltest.c tests/strlen/03_special_test.c tests/strlen/04_longtest.c \
	   tests/strlen/05_test05.c tests/strlen/06_test06.c tests/strlen/07_test07.c \
	   tests/strlen/08_test08.c tests/strlen/09_test09.c tests/strlen/10_test10.c \
	   tests/strlen/11_test11.c tests/strlen/12_test12.c tests/strncmp/00_laucher.c \
	   tests/strncmp/01_basic.c tests/strncmp/02_greater.c tests/strncmp/03_smaller.c \
	   tests/routine/00_launcher.c tests/routine/01_ok_test.c \
	   tests/routine/02_ko_test.c tests/routine/03_sigsev_test.c \
	   tests/routine/04_bus_test.c

OFILES = $(CFILES:.c=.o)

%.o	: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@
all: $(NAME)
$(NAME): $(OFILES)
	$(AR) $(NAME) $(OFILES)
bonus: $(BOFILES)
	$(AR) $(NAME) $(BOFILES)
clean:
	rm -f $(OFILES) $(BOFILES)
fclean:	clean
	rm -f $(NAME)
re: fclean all
.PHONY:  all bonus clean fclean re
