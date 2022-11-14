/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   images.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 15:12:50 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/14 18:26:41 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "unistd.h"

void	atlas_player(t_game *game, int dir, int sprite)
{
	unsigned int	xy[2];
	unsigned int	wh[2];

	wh[0] = 22;
	wh[1] = 22;
	xy[y] = dir * 22;
	xy[x] = (sprite * 22) + 22;
	game->plr.p_img = mlx_texture_area_to_image
		(game->mlx, game->plr.p_text, xy, wh);
}

void	create_player(t_game *game)
{
	game->plr.p_text = mlx_load_png("textures/char/spritesheet.png");
	atlas_player(game, up, idle);
	atlas_player(game, down, idle);
	atlas_player(game, up, move_1);
	mlx_image_to_window(game->mlx, game->plr.p_img,
		game->map->player[1] * game->wi, game->map->player[0] * game->hi);
	game->plr.x = &game->plr.p_img->instances->x;
	game->plr.y = &game->plr.p_img->instances->y;
	game->plr.speed_x = 0;
	game->plr.speed_y = 0;
}

void	create_exit(t_game *game)
{
	game->exit.e_text = mlx_load_png
		("textures/exit.png");
	game->exit.e_img = mlx_texture_to_image(game->mlx, game->exit.e_text);
	mlx_image_to_window(game->mlx, game->exit.e_img,
		game->map->exit[1] * game->hi, game->map->exit[0] * game->wi);
}

void	images(t_map *map)
{
	t_game		game;

	game.map = map;
	create_world(&game);
	create_exit(&game);
	create_player(&game);
	mlx_loop_hook(game.mlx, &move_hook, &game);
	mlx_loop_hook(game.mlx, &exit_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
}
