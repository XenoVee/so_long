/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 20:55:06 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/02 17:46:04 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	movement_hook(void *g)
{
	t_game		*game;

	game = (t_game *)g;
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
	{
		player_moveup(game);
		player_moveup(game);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
	{
		player_movedown(game);
		player_movedown(game);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		player_moveleft(game);
		player_moveleft(game);
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		player_moveright(game);
		player_moveright(game);
	}
}

void	exit_hook(void *g)
{
	t_game		*game;

	game = (t_game *)g;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
}
