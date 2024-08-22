# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abekri <abekri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 19:54:17 by abekri            #+#    #+#              #
#    Updated: 2024/07/11 01:24:44 by abekri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS 	= 	philo.c one_philos.c utils.c destroy_simulation.c \
			init_simulation.c monitor_philo.c philo_routine.c \
			process_init.c init_data.c init_philos.c

HEADER	=	philo.h

OBJ		=	$(patsubst %.c, %.o, $(SRCS))

CC 		= 	gcc
CFLAGG 	= 	-pthread -Wall -Wextra -Werror -pthread -Wall -Wextra -Werror -fsanitize=address -g -I$(HEADER)


all		:	${NAME}

$(NAME)	:	$(OBJ)	$(HEADER)
	$(CC) $(CFLAGG) $(OBJ) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -f $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all
