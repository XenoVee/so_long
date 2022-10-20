# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rmaes <rmaes@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/08/01 13:10:16 by rmaes         #+#    #+#                  #
#    Updated: 2022/10/19 16:51:20 by rmaes         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


SOURCES_DIR = sources/

FILES =	check.c \
		file.c \
		parsing.c \
		so_long.c \
		utils.c \

SOURCES = $(addprefix $(SOURCES_DIR), $(FILES))

CFLAGS = -Wall -Wextra -Werror
CC = gcc
LIBFT = ./libftprintf
LIBFT_NAME = libftprintf/libft.a
NAME = so_long
TEST = test

all: $(NAME)

$(LIBFT_NAME):
	@echo 'Making libft'
	@make -C $(LIBFT)

$(TEST): $(SOURCES) $(LIBFT_NAME)
	@$(CC) -g -o $@ $^

$(NAME): $(SOURCES) $(LIBFT_NAME)
	@echo $(SOURCES)
	$(CC) -o $@ $^

clean:
	@echo "cleaning libft object files"
	@make clean -C $(LIBFT)
	@echo "removing so_long"
	@rm -f $(NAME)

fclean: clean
	@echo "removing libft.a"
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
