/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 15:12:50 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/29 14:32:51 by rmaes         ########   odam.nl         */
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

void	window(t_map *map)
{
	t_game		game;

	game.map = map;
	create_world(&game);
	create_exit(&game);
	create_player(&game);
	create_collectibles(&game, game.map->map);
	mlx_loop_hook(game.mlx, &move_hook, &game);
	mlx_loop_hook(game.mlx, &exit_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
}
