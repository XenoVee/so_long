# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rmaes <rmaes@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/08/01 13:10:16 by rmaes         #+#    #+#                  #
#    Updated: 2022/11/29 14:33:42 by rmaes         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


SOURCES_DIR = sources/

BONUS_DIR = dir_bonus/bonus_sources/

FILES =			check.c \
				file.c \
				parsing.c \
				utils.c \
				solve_check.c \
				window.c \
				hooks.c \
				player_move.c \
				collectibles.c \
				world.c \
				exit.c \
				put_wall.c \
				player.c \
				collision.c \

BONUS_FILES =	collectibles.c \
				doors.c \
				draw_rock.c \
				ft_create_map.c \
				ft_fill_map.c \
				ft_print_map.c \
				ft_seedconv.c \
				ft_setup_params.c \
				mapgen.c \
				rocks.c \
				rooms.c \
				rooms_checks.c \
				rooms_draw.c \
				utilities.c \

FILE_MAIN = so_long.c

FILE_BONUS_MAIN = so_long_mapgen.c

SOURCES = $(addprefix $(SOURCES_DIR), $(FILES))

SOURCE_MAIN = $(addprefix $(SOURCES_DIR), $(FILE_MAIN))

BONUS_SOURCES = $(addprefix $(BONUS_DIR), $(BONUS_FILES))

SOURCE_BONUS_MAIN = $(addprefix $(BONUS_DIR), $(FILE_BONUS_MAIN))

CFLAGS = -Wall -Wextra -Werror
CC = gcc
LIBFT = ./libftprintf
LIBFT_NAME = libftprintf/libft.a
MLX_NAME = MLX42/libmlx42.a
MLX_FLAGS = -I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
NAME = so_long
TEST = test
BONUS = bonus

all: $(NAME)

$(LIBFT_NAME):
	@echo 'Making libft'
	@make -C $(LIBFT)

$(TEST): $(SOURCES) $(LIBFT_NAME) $(MLX_NAME) $(SOURCE_MAIN)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) -g -fsanitize=address -o $@ $^

$(BONUS): $(SOURCES) $(LIBFT_NAME) $(MLX_NAME) $(SOURCE_BONUS_MAIN) $(BONUS_SOURCES)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) -g -o $@ $^

$(NAME): $(SOURCES) $(LIBFT_NAME) $(MLX_NAME) $(SOURCE_MAIN)
	@echo $(SOURCES)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $@ $^

clean:
	@echo "cleaning libft object files"
	@make clean -C $(LIBFT)
	@echo "removing so_long"
	@rm -f $(NAME) $(TEST) $(BONUS)

fclean: clean
	@echo "removing libft.a"
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re test
