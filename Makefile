# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rmaes <rmaes@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/08/01 13:10:16 by rmaes         #+#    #+#                  #
#    Updated: 2022/10/17 18:24:55 by rmaes         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SOURCES = *.c
OBJECTS = $(SOURCES:.c=.o)
HEADER = so_long.h
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

$(TEST): $(SOURCES)
	@$(CC) -g -o $@ $^

$(NAME): $(SOURCES) $(LIBFT_NAME)
	@$(CC) -o $@ $^

%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $^

clean:
	@echo "cleaning libft object files"
	@make clean -C $(LIBFT)

fclean: clean
	@echo "removing so_long"
	@rm -f $(NAME)
	@echo "removing libft.a"
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
