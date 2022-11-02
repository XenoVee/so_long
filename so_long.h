/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 15:15:44 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/02 22:25:56 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libftprintf/libft.h"
# include "err.h"
# include "errno.h"
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_player
{
	mlx_image_t		*p_img;
	int				*x;
	int				*y;
	mlx_texture_t	*p_text;
}				t_player;

typedef struct s_map
{
	unsigned int	x;
	unsigned int	y;
	char			**map;
	int				player[2];
}				t_map;

typedef struct s_world
{
	mlx_image_t		*w_img;
	mlx_texture_t	*w_text;
}				t_world;

typedef struct s_game
{
	int			wi;
	int			hi;
	mlx_t		*mlx;
	t_world		*wld;
	t_player	*plr;
	t_map		*map;
}				t_game;

void	error(char *errmsg);
void	multi_error(char *errmsg, int *n);
int		check_ext(char *file);
void	open_file(char *filepath, t_map *map);
void	parsing(t_map *map);
void	check_map(t_map *map, t_err *err);
int		char_valid(char c, char *v_chars);
void	null_err(t_err *err);
void	solve_check(t_map *map, t_err *err);
void	create_player(t_game *game);
void	images(t_map *map);
void	movement_hook(void *g);
void	exit_hook(void *g);
void	player_moveup(t_game *game);
void	player_movedown(t_game *game);
void	player_moveleft(t_game *game);
void	player_moveright(t_game *game);
void	mapgen(int argc, char **argv, t_map *map);

#endif
