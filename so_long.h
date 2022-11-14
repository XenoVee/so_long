/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 15:15:44 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/14 18:27:54 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libftprintf/libft.h"
# include "headerfiles/err.h"
# include "errno.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "headerfiles/struct.h"
# include "headerfiles/t_player.h"

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
void	create_world(t_game *game);
void	images(t_map *map);
void	exit_hook(void *g);
void	move_hook(void *g);
void	player_moveup(t_game *game, int s);
void	player_movedown(t_game *game, int s);
void	player_moveleft(t_game *game, int s);
void	player_moveright(t_game *game, int s);
void	mapgen(int argc, char **argv, t_map *map);
void	create_collectibles(t_game *game);
void	read_buf(int fd, char *buf, int nbyte);
void	shift_buf(char *buf);
void	put_wall(t_game *game, int x, int y);
void	atlas_player(t_game *game, int dir, int sprite);
void	create_player(t_game *game);

#endif
