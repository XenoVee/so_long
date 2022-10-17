# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rmaes <rmaes@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/08/01 13:10:16 by rmaes         #+#    #+#                  #
#    Updated: 2022/10/17 17:36:28 by rmaes         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SOURCES = *.c
OBJECTS = $(SOURCES:.c=.o)
HEADER = so_long.h
CFLAGS = -Wall -Wextra -Werror
CC = gcc
LIBFT = libft/libft.a
NAME = so_long
TEST = test

all: $(NAME)

$(LIBFT):
	@echo 'Making libft'
	@make -C ./libft

$(TEST): $(SOURCES)
	@$(CC) -g -o $@ $^

$(NAME): $(SOURCES) $(LIBFT)
	@$(CC) -o $@ $^

%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $^

clean:
	@echo "cleaning libft object files"
	@make clean -C ./libft

fclean: clean
	@echo "removing so_long"
	@rm -f $(NAME)
	@echo "removing libft.a"
	@make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re
