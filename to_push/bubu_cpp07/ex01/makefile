EX01		=	iter
CC			=	g++
AR			=	ar rcs
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror
SRC			=	main.cpp
OBJ_DIR		=	obj
EX00_OBJ	=	$(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all: $(EX01)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(EX01): $(EX00_OBJ)
	@$(CC) $(EX00_OBJ) -o $(EX01)
	@echo "\033[31m------------------***༺ (\033[31m\033[32mCPP_Module 07 Ex01 Compiled!\033[31m)༻***------------------\n\033[0m"

exec: all
	@./$(EX01)

clean:
	@$(RM) $(OBJ_DIR)
	clear

fclean: clean
	@$(RM) $(EX01)
	clear

re: fclean all

.PHONY: all clean fclean re
