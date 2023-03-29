NAME		=	btc

#-------------------PATH----------------------

#-------------------COMPILATION----------------------

CC			=	c++
FLAGS		=	-Wall -Werror -Wextra
STD_LIB		=	-std=c++98
#-------------------SOURCES FILES----------------------

SRCS	=	main.cpp \
			BitcoinExchange.cpp \
			Utils.cpp

#-------------------OBJECTS----------------------

OBJS_SRCS	=	$(SRCS:.c=.o)

#-------------------COLORS----------------------

RED			=	\x1b[31m

YELLOW		=	\x1b[33m

GREEN		=	\x1b[32m

NO_COLOR	=	\x1b[0m


#-------------------RULES-----------------------
%.o: %.c
		@printf "$(YELLOW)Generating $(NAME) objects... %-33.33s\r$(NO_COLOR)" $@
		@$(CC) $(FLAGS) $(STD_LIB) -c $< -o $@

$(NAME):	$(OBJS_SRCS)
			@echo "\n"
			@echo "$(GREEN)\nCompiling $(NAME)...$(NO_COLOR)"
			@$(CC) $(FLAGS) $(STD_LIB) $(OBJS_SRCS) -o $(NAME)
			@echo "$(NAME) ready to be used!"

all:	$(NAME)

clean:
		@echo "$(RED)Deleting executables...\n$(NO_COLOR)"
		@rm -f $(NAME)

fclean:	clean

re: fclean all

.PHONY: all clean fclean re