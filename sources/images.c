/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   images.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 15:12:50 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/16 21:24:27 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "unistd.h"

void	write_moves(t_game *game)
{
	static mlx_image_t	*text = NULL;
	static int			moves = 0;

	if (text != NULL)
		mlx_delete_image(game->mlx, text);
	text = mlx_put_string(game->mlx, ft_itoa(moves / game->wi), 1, 1);
	moves += ft_abs(game->plr.speed_x) + ft_abs(game->plr.speed_y);
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
	create_collectibles(&game, game.map->map);
	mlx_loop_hook(game.mlx, &move_hook, &game);
	mlx_loop_hook(game.mlx, &exit_hook, &game);
	mlx_loop_hook(game.mlx, &collect_check, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
}
