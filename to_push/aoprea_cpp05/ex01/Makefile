CFLAGS := -Wall -Wextra -Werror -std=c++98

NAME := ex01

SRCS := main.cpp Bureaucrat.cpp Form.cpp

OBJS = $(SRCS:.cpp=.opp)

all: $(NAME)

%.opp: %.cpp
	c++ $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	c++ $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re