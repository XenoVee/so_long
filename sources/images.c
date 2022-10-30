/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   images.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 15:12:50 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/30 21:38:21 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "unistd.h"

void	create_player(t_game *game)
{
	game->plr->p_text = mlx_load_png
		("/Users/rmaes/Projects/so_long/textures/brick.png");
	game->plr->p_img = mlx_texture_to_image(game->mlx, game->plr->p_text);
	mlx_image_to_window(game->mlx, game->plr->p_img,
		game->map->player[1] * game->hi, game->map->player[0] * game->wi);
	game->plr->x = &game->plr->p_img->instances->x;
	game->plr->y = &game->plr->p_img->instances->y;
}

void	create_world_image(t_game *game)
{
	int		ix;
	int		iy;

	ix = 0;
	while (game->map->map[ix])
	{
		iy = 0;
		while (game->map->map[ix][iy])
		{
			if (game->map->map[ix][iy] == '1')
				mlx_draw_texture(game->wld->w_img, game->wld->w_text,
					iy * game->hi, ix * game->wi);
			iy++;
		}
		ix++;
	}
}

void	create_world(t_game *game)
{
	t_world	*wld;
	t_map	*map;

	wld = game->wld;
	map = game->map;
	wld->w_text = mlx_load_png
		("/Users/rmaes/Projects/so_long/textures/brick.png");
	game->wi = wld->w_text->width;
	game->hi = wld->w_text->height;
	game->mlx = mlx_init(map->y * game->hi, map->x * game->wi,
			"so_long", false);
	if (!game->mlx)
		error(ERR_MLX_INIT);
	wld->w_img = mlx_new_image(game->mlx, map->y * game->hi, map->x * game->wi);
	create_world_image(game);
	mlx_image_to_window(game->mlx, wld->w_img, 0, 0);
}

void	images(t_map *map)
{
	t_player	plr;
	t_world		wld;
	t_game		game;

	game.plr = &plr;
	game.wld = &wld;
	game.map = map;
	create_world(&game);
	create_player(&game);
	mlx_loop_hook(game.mlx, &movement_hook, &game);
	mlx_loop_hook(game.mlx, &exit_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
}
