# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 19:59:29 by miheider          #+#    #+#              #
#    Updated: 2024/09/10 19:02:22 by vschneid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################################################################
######                            PROPERTIES                             ######
###############################################################################

CC		= cc
RM		= rm -rf
CFLAGS		= -Wall -Wextra -Werror -I./includes -I./libft 
MAKEFLAGS	= -j$(nproc) --no-print-directory

NAME		= cub3D
SRCSDIR		= srcs
SRCS		= \
			${SRCSDIR}/main.c \
			${SRCSDIR}/init.c \
			${SRCSDIR}/ray.c \
			${SRCSDIR}/distance.c \
			${SRCSDIR}/open_walls.c \
			${SRCSDIR}/check_open_spots.c \
			${SRCSDIR}/handle_map.c \
			${SRCSDIR}/handle_map_2.c \
			${SRCSDIR}/save_map.c \
			${SRCSDIR}/check_map.c \
			${SRCSDIR}/events.c \
			${SRCSDIR}/free_exit.c \
			${SRCSDIR}/free_exit_2.c \
			${SRCSDIR}/walls.c \
			${SRCSDIR}/utils.c \
			${SRCSDIR}/utils_2.c \
			${SRCSDIR}/map_to_array.c \
			${SRCSDIR}/invalid_map_values.c \
			${SRCSDIR}/handle_colors.c \
			${SRCSDIR}/handle_colors_2.c \
			${SRCSDIR}/save_player.c \
			${SRCSDIR}/check_textures.c \
			${SRCSDIR}/max_map_values.c \

LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a

OBJSDIR		= objs
OBJS		= $(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))
DEPS		= $(addprefix $(OBJSDIR)/, $(SRCS:.c=.d))

###############################################################################
######                               RULES                               ######
###############################################################################

LIBFT_MAKE = $(MAKE) -C $(LIBFT_PATH)

all		: $(NAME)

$(NAME)	: ${OBJS} $(LIBFT)
		@echo linking...
		@$(CC) $(OBJS) $(LIBFT) -o $@ -lmlx -lXext -lX11 -lm
		@if [ $$? -eq 0 ]; then echo "\033[1;32mready to play\033[0m"; else echo "\033[1;31mnot ready to play\033[0m"; fi

$(LIBFT):
		@echo "Building libft..."
		@$(LIBFT_MAKE)

${OBJSDIR}/%.o	: %.c | $(OBJSDIR)
		@echo loading...
		@mkdir -p $(dir $@)
		@${CC} ${CFLAGS} -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(OBJSDIR):
		@mkdir -p $(OBJSDIR)

clean	:
		@$(LIBFT_MAKE) clean
		@$(RM) $(OBJSDIR)
		@echo "Cleaned"

fclean	:
		@$(LIBFT_MAKE) fclean
		@$(RM) $(OBJSDIR) $(NAME)

re		:
		@$(LIBFT_MAKE) fclean
		@$(RM) $(OBJSDIR) $(NAME)
		$(MAKE) all

-include $(DEPS)

.PHONY: all clean fclean bonus re test run mac