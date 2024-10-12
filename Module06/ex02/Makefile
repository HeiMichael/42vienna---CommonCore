# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miheider <miheider@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/27 08:19:55 by miheider          #+#    #+#              #
#    Updated: 2024/10/12 13:11:14 by miheider         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################################################################
######                            PROPERTIES                             ######
###############################################################################

CXX			= c++
RM			= rm -rf
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic -I./includes -MD -MP -g
MAKEFLAGS	= -j$(nproc) --no-print-directory

NAME		= identify
SRCSDIR		= srcs
OBJSDIR		= objs

SRCS		= \
				${SRCSDIR}/main.cpp \
				${SRCSDIR}/Base.cpp \
				${SRCSDIR}/A.cpp \
				${SRCSDIR}/B.cpp \
				${SRCSDIR}/C.cpp 

OBJS		= $(addprefix $(OBJSDIR)/, $(notdir $(SRCS:.cpp=.o)))
DEPS		= $(addprefix $(OBJSDIR)/, $(notdir $(SRCS:.cpp=.d)))

###############################################################################
######                               RULES                               ######
###############################################################################

all		: $(NAME)

$(NAME)	: ${OBJS}
		@echo linking...
		@$(CXX) -o $@ $^
		@if [ $$? -eq 0 ]; then echo "\033[1;32mready\033[0m"; else echo "\033[1;31mnot ready\033[0m"; fi

# Rule for compiling .cpp to .o files
$(OBJSDIR)/%.o : $(SRCSDIR)/%.cpp
		@echo loading $<...
		@mkdir -p $(OBJSDIR)
		@$(CXX) ${CXXFLAGS} -c $< -o $@

clean	:
		@$(RM) ${OBJSDIR}
		@echo "Cleaned"

fclean	:
		@$(RM) ${OBJSDIR} $(NAME)

re		:
		@$(RM) ${OBJSDIR} $(NAME)
		$(MAKE) all

-include $(DEPS)

.PHONY: all clean fclean re