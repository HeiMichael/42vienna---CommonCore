# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miheider <miheider@42>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 17:18:38 by miheider          #+#    #+#              #
#    Updated: 2023/11/19 16:39:02 by miheider         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# M A K F I L E

NAME = fractol

SRCS = calculate.c connection.c events.c fractol.c julia.c mandelbrot.c \
       rendering.c color_presets.c change_color.c

B_SRCS = calculate_bonus.c connection_bonus.c events_bonus.c fractol_bonus.c \
         julia_bonus.c mandelbrot_bonus.c rendering_bonus.c \
         color_presets_bonus.c change_color_bonus.c burning_ship_bonus.c

OBJS = $(addprefix objs/,$(SRCS:.c=.o))
B_OBJS = $(addprefix objs/,$(B_SRCS:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Iincludes
LIBFT_PATH = ./libft
RM = rm -rf

LIBFT_MAKE = $(MAKE) -C $(LIBFT_PATH)

all: $(NAME)

$(NAME): $(OBJS)
	@$(LIBFT_MAKE)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH)/libft.a libmlx.a -o $(NAME) -lmlx -lXext -lX11 -lm

bonus: $(B_OBJS)
	@$(LIBFT_MAKE)
	@$(CC) $(CFLAGS) $(B_OBJS) $(LIBFT_PATH)/libft.a libmlx.a -o $(NAME)_bonus -lmlx -lXext -lX11 -lm

objs/%.o: %.c | objs
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(CC) $(CFLAGS) -MM -MF $(patsubst %.o,%.d,$@) -MT $@ $<

-include $(OBJS:.o=.d) $(B_OBJS:.o=.d)

objs:
	@mkdir -p objs

clean:
	@$(LIBFT_MAKE) clean
	@$(RM) objs

fclean: clean
	@$(LIBFT_MAKE) fclean
	@$(RM) $(NAME) $(NAME)_bonus

re: fclean all

.PHONY: clean fclean re all bonus

