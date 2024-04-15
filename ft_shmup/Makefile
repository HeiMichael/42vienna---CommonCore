NAME			= 	ft_shmup	

SRCDIR			=	srcs
SRCS			=	\
					$(SRCDIR)/Menu.cpp \
					$(SRCDIR)/Backscroll.cpp \
					$(SRCDIR)/Object.cpp \
					$(SRCDIR)/Bullet.cpp \
					$(SRCDIR)/Boss.cpp \
					$(SRCDIR)/Player.cpp \
					$(SRCDIR)/Enemy.cpp \
					$(SRCDIR)/Spaceship.cpp \
					$(SRCDIR)/Game.cpp \
					$(SRCDIR)/main.cpp \

OBJDIR			=	$(SRCDIR)/objs
OBJS			=	$(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o) 
DEPS			=	$(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.d)

#-------FLAGS------------------------- 
CC				= 	c++
FLAGS			= 	-Wall -Wextra -Werror -g -MD -MP
LIBS			= 	-lncursesw 
INCLUDE			=	-I ./inc
RM				= 	rm -rf

all: $(NAME)


$(NAME): $(OBJS)
	@echo "Linking..."
	@$(CC) $(FLAGS) $(LIBS)  $(OBJS) -o $(NAME)  

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo "Compiling..."
	@mkdir -p $(dir $@)
	@$(CC) -c $(FLAGS) $(INCLUDE) $< -o $@ 
	
clean:
	@$(RM) $(OBJDIR)
	@echo "Cleaned"

fclean:
	@$(RM) $(OBJDIR) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY:	all clean fclean re bonus
