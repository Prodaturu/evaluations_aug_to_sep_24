CC:= g++

NAME:= EX

FLAGS+= -Wall -Werror -Wextra -std=c++98 -g

SRC:=	main.cpp Span.cpp

OBJ:=  $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(FLAGS) -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean
	@make all

.PHONY: clean fclean re
