# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgiochal < sgiochal@student.42vienna.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 16:31:03 by sgiochal          #+#    #+#              #
#    Updated: 2023/11/11 21:25:01 by sgiochal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S = src/
O = obj/
I = inc/
D = dep/
CC = cc

NAME = wordle
		
SRC =	$Scolor_update.c \
		$Sprinting.c \
		$Sutils.c \
		$Swordle.c  

CFLAGS = -Wextra -Werror -Wall
CFLAGS += -I$I
#include settings.mk

OBJ = $(SRC:$S%=$O%.o)
DEP = $(SRC:$S%=$D%.d)

RM = /bin/rm -rf
RMDIR = /bin/rmdir

.PHONY: all clean fclean re

all: $(NAME)

$O:
	@mkdir $@

$(OBJ): | $O

$O%.o: $S%
	$(CC) $(CFLAGS) -c $< -o $@ -g 

$D:
	@mkdir $@

$(DEP): | $D

$D%.d: $S%
	$(CC) $(CFLAGS) -MM -MF $@ -MT "$O$*.o $@" $< 

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

cleanobj:
	$(RM) $(wildcard $(OBJ))

cleanobjdir: cleanobj
	$(RM) $O

cleandep:
	$(RM) $(wildcard $(DEP))

cleandepdir: cleandep
	$(RM) $D

clean: cleanobjdir cleandepdir

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEP)
