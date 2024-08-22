EX00		=	Temp
CC			=	g++
AR			=	ar rcs
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror
SRC			=	main.cpp
OBJ_DIR		=	obj
EX00_OBJ	=	$(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all: $(EX00)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(EX00): $(EX00_OBJ)
	@$(CC) $(EX00_OBJ) -o $(EX00)
	@echo "\033[31m------------------***༺ (\033[31m\033[32mCPP_Module 07 Ex00 Compiled!\033[31m)༻***------------------\n\033[0m"

exec: all
	@./$(EX00)

clean:
	@$(RM) $(OBJ_DIR)
	clear

fclean: clean
	@$(RM) $(EX00)
	clear

re: fclean all

.PHONY: all clean fclean re
