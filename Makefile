# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rmaes <rmaes@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/08/01 13:10:16 by rmaes         #+#    #+#                  #
#    Updated: 2022/10/28 15:17:57 by rmaes         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


SOURCES_DIR = sources/

FILES =	check.c \
		file.c \
		parsing.c \
		so_long.c \
		utils.c \
		solve_check.c \
		images.c \

SOURCES = $(addprefix $(SOURCES_DIR), $(FILES))

CFLAGS = -Wall -Wextra -Werror
CC = gcc
LIBFT = ./libftprintf
LIBFT_NAME = libftprintf/libft.a
MLX_NAME = MLX42/libmlx42.a
MLX_FLAGS = -I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
NAME = so_long
TEST = test

all: $(NAME)

$(LIBFT_NAME):
	@echo 'Making libft'
	@make -C $(LIBFT)

$(TEST): $(SOURCES) $(LIBFT_NAME) $(MLX_NAME) 
	@$(CC) $(CFLAGS) $(MLX_FLAGS) -g -o $@ $^ 

$(NAME): $(SOURCES) $(LIBFT_NAME) $(MLX_NAME) 
	@echo $(SOURCES)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $@ $^ 

clean:
	@echo "cleaning libft object files"
	@make clean -C $(LIBFT)
	@echo "removing so_long"
	@rm -f $(NAME) $(TEST)

fclean: clean
	@echo "removing libft.a"
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
