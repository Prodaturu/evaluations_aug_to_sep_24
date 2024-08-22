EX02		=	Array
CC			=	g++
AR			=	ar rcs
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror
SRC			=	main.cpp 
OBJ_DIR		=	obj
EX02_OBJ	=	$(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all: $(EX02)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(EX02): $(EX02_OBJ)
	@$(CC) $(EX02_OBJ) -o $(EX02)
	@echo "\033[31m------------------***༺ (\033[31m\033[32mCPP_Module 07 Ex02 Compiled!\033[31m)༻***------------------\n\033[0m"

exec: all
	@./$(EX02)

clean:
	@$(RM) $(OBJ_DIR)
	clear

fclean: clean
	@$(RM) $(EX02)
	clear

re: fclean all

.PHONY: all clean fclean re
