CFLAGS := -Wall -Wextra -Werror -std=c++98

NAME := ex03

SRCS := main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

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