# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miheider <miheider@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 19:59:29 by miheider          #+#    #+#              #
#    Updated: 2024/06/01 14:12:10 by miheider         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################################################################
######                            PROPERTIES                             ######
###############################################################################

CC		= cc
RM		= rm -rf
CFLAGS		= -Wall -Wextra -Werror -I./includes -MD -MP
MAKEFLAGS	= -j$(nproc) --no-print-directory

NAME		= philo
SRCSDIR		= srcs
SRCS		= \
			${SRCSDIR}/check_input.c \
			${SRCSDIR}/init.c \
			${SRCSDIR}/philo_utils.c \
			${SRCSDIR}/philo_utils_two.c \
			${SRCSDIR}/error.c \
			${SRCSDIR}/main.c \
			${SRCSDIR}/routine.c \
			${SRCSDIR}/threads.c \
			${SRCSDIR}/monitor.c \
			${SRCSDIR}/time.c 

OBJSDIR		= objs
OBJS		= $(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))
DEPS		= $(addprefix $(OBJSDIR)/, $(SRCS:.c=.d))

###############################################################################
######                               RULES                               ######
###############################################################################

all		: $(NAME)

$(NAME)	: ${OBJS}
		@echo linking...
		@$(CC) -o $@ $^
		@if [ $$? -eq 0 ]; then echo "\033[1;32mPhilos are ready to eat\033[0m"; else echo "\033[1;31mPhilos are not ready to eat\033[0m"; fi

${OBJSDIR}/%.o	: %.c
		@echo loading...
		@mkdir -p $(dir $@)
		@${CC} ${CFLAGS} -c $< -o $@

clean	:
		@$(RM) $(OBJSDIR)
		@echo "Cleaned"

fclean	:
		@$(RM) $(OBJSDIR) $(NAME)

re		:
		@$(RM) $(OBJSDIR) $(NAME)
		$(MAKE) all

-include $(DEPS)

.PHONY: all clean fclean re
