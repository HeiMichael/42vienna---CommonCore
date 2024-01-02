# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miheider <miheider@42>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 20:49:55 by miheider          #+#    #+#              #
#    Updated: 2024/01/02 17:24:57 by miheider         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# M A K E F I L E

NAME_server = server
NAME_client = client
SRCS_server = server.c
SRCS_client = client.c

OBJS_server = $(addprefix objs_server/,$(SRCS_server:.c=.o))
OBJS_client = $(addprefix objs_client/,$(SRCS_client:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -Iincludes
LIBFT_PATH = -Llibft -lft
PRINT_PATH = -Lft_printf -lftprintf
RM = rm -rf

LIBFT_MAKE = $(MAKE) -C ./libft
PRINT_MAKE = $(MAKE) -C ./ft_printf

all: $(NAME_server) $(NAME_client)

$(NAME_server): $(OBJS_server)
	@$(LIBFT_MAKE)
	@$(PRINT_MAKE)
	@$(CC) $(CFLAGS) $(OBJS_server) -o $(NAME_server) $(LIBFT_PATH) $(PRINT_PATH)
	@if [ $$? -eq 0 ]; then echo "\033[1;32mserver [OK]\033[0m"; else echo "\033[1;31mserver [KO]\033[0m"; fi

$(NAME_client): $(OBJS_client)
	@$(LIBFT_MAKE)
	@$(LIBFT_MAKE)
	@$(CC) $(CFLAGS) $(OBJS_client) $(LIBFT_PATH) $(PRINT_PATH) -o $(NAME_client)
	@if [ $$? -eq 0 ]; then echo "\033[1;32mclient [OK]\033[0m"; else echo "\033[1;31mclient [KO]\033[0m"; fi

objs_server/%.o: %.c | objs_server
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(CC) $(CFLAGS) -MM -MF $(patsubst %.o,%.d,$@) -MT $@ $<

objs_client/%.o: %.c | objs_client
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(CC) $(CFLAGS) -MM -MF $(patsubst %.o,%.d,$@) -MT $@ $<

-include $(OBJS_server:.o=.d) $(B_OBJS_server:.o=.d)
-include $(OBJS_client:.o=.d) $(B_OBJS_client:.o=.d)

objs_server:
	@mkdir -p objs_server

objs_client:
	@mkdir -p objs_client

clean:
	@$(LIBFT_MAKE) clean
	@$(PRINT_MAKE) clean
	@$(RM) objs_server
	@$(RM) objs_client

fclean: clean
	@$(LIBFT_MAKE) fclean
	@$(LIBFT_MAKE) fclean
	@$(RM) $(NAME_server) $(NAME_client)

re: fclean all

.PHONY: clean fclean re all