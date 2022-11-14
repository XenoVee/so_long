/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 18:27:31 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/14 18:27:43 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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