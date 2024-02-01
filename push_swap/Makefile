# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miheider <miheider@42>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/05 17:18:38 by miheider          #+#    #+#              #
#    Updated: 2024/01/23 23:38:13 by miheider         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# M A K F I L E

NAME = push_swap

SRCS = checks.c main.c push_swap_utils.c push_swap_utils2.c error.c \
	   algo_simple.c swap.c rotate.c reverse_rotate.c push.c \
	   algo_complex.c algorithm.c \

OBJS = $(addprefix objs/,$(SRCS:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Iincludes
LIBFT_PATH = ./libft
PRINT_PATH = ./ft_printf
RM = rm -rf

LIBFT_MAKE = $(MAKE) -C $(LIBFT_PATH)
PRINT_MAKE = $(MAKE) -C $(PRINT_PATH)

all: $(NAME)

$(NAME): $(OBJS)
	@$(LIBFT_MAKE)
	@$(PRINT_MAKE)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH)/libft.a $(PRINT_PATH)/libftprintf.a -o $(NAME)

objs/%.o: %.c | objs
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(CC) $(CFLAGS) -MM -MF $(patsubst %.o,%.d,$@) -MT $@ $<

-include $(OBJS:.o=.d) $(B_OBJS:.o=.d)

objs:
	@mkdir -p objs

clean:
	@$(LIBFT_MAKE) clean
	@$(PRINT_MAKE) clean
	@$(RM) objs

fclean: clean
	@$(LIBFT_MAKE) fclean
	@$(PRINT_MAKE) fclean
	@$(RM) $(NAME) #$(NAME)_bonus

re: fclean all

.PHONY: clean fclean re all
