/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 20:55:06 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/30 22:21:06 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	movement_hook(void *g)
{
	t_game		*game;
	// static int	cooldown = 0;

	game = (t_game *)g;
	// if (cooldown == 0)
	// {
		if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
			player_moveup(game);
		if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
			player_movedown(game);
		if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
			player_moveleft(game);
		if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
			player_moveright(game);
	// 	cooldown = 8;
	// }
	// else
	// 	cooldown--;
}

void	exit_hook(void *g)
{
	t_game		*game;

	game = (t_game *)g;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
}
