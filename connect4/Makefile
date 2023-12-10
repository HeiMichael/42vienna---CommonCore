NAME = connect4
CC = cc
CC1 = clang
CC2 = gcc
CFLAGS = -Wall -Werror -Wextra -g
HEADER = connect4.h

#Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRC = check_for_winning.c checking_score.c connect4.c destroyer.c helpers.c \
			display.c ft_printf.c get_next_line.c get_next_line_utils.c printf_utils.c \
			checking_for_two.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -g -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created!$(DEF_COLOR)"

clean:
	rm -f $(OBJ) $(BN_OBJ)

fclean: clean
	rm -f $(NAME)

smooth: all clean

re:
	@$(MAKE) fclean
	@$(MAKE) all

celan:
	@echo "$(YELLOW)Lol, that's not quite what you wanted to write, huh?$(DEF_COLOR)"
	
fcelan: celan

clear: celan

strict:
	@echo "$(GREEN)Compiling with $(YELLOW)$(CC1)$(GREEN)...$(DEF_COLOR)"
	@$(MAKE) all CC=$(CC1)
	@echo "$(GREEN)Cleaning up...$(DEF_COLOR)"
	@$(MAKE) fclean
	@echo "$(GREEN)Compiling with $(YELLOW)$(CC2)$(GREEN)...$(DEF_COLOR)"
	@$(MAKE) all CC=$(CC2)
	@echo "$(GREEN)Cleaning up again...$(DEF_COLOR)"
	@$(MAKE) clean
	@echo "$(GREEN)Tested for both compilers.$(DEF_COLOR)"

.PHONY: all clean fclean re bonus strict smooth celan fcelan clear
