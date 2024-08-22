.silent:

NAME	:= miniRT
CC		:= cc 
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g #-fsanitize=address
LIBMLX	:= ./MLX42
SRCS 	:= main.c \
			./garbage_collector/garbage_collector.c \
			./garbage_collector/garbage_remover.c \
			./parser/parser.c \

LIBFT	:= ./libft
GNL 	:= ./gnl42

# *** *** *** Header files required *** *** *** #

HEADERS_FILES := ./include/garbage_collector.h \
			./include/minirt.h \
			./include/parser.h \

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -fsanitize=address
INCLUDE := -L $(LIBFT) -lft -L $(GNL) -lgnl
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	if [ ! -d "$(LIBMLX)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git; \
		cd $(LIBMLX) && git pull; \
	else \
		echo "$(LIBMLX) already exists, pulling latest changes instead."; \
		cd $(LIBMLX) && git pull; \
	fi
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -sC $(LIBMLX)/build -j4

%.o: %.c $(HEADERS_FILES)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@make -sC $(LIBFT)
	@make -sC $(GNL)
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -sC $(LIBMLX)/build -j4
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(INCLUDE) -o $(NAME) -lm

bonus: $(NAME)

clean:
	@rm -rf $(OBJS) $(BOBJS) $(LIBMLX)/build
	@cd $(LIBFT) && $(MAKE) clean
	@cd $(GNL) && $(MAKE) clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBMLX)
	@cd $(GNL) && $(MAKE) fclean
	@cd $(LIBFT) && $(MAKE) fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx, bonus