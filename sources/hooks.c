/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 20:55:06 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/14 13:14:46 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	movement_hook(void *g)
{
	t_game		*game;
	int			speed;

	game = (t_game *)g;
	speed = 2;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT))
		speed *= speed;
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		player_moveup(game, speed);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		player_movedown(game, speed);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		player_moveleft(game, speed);
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		player_moveright(game, speed);
}

void	exit_hook(void *g)
{
	t_game		*game;

	game = (t_game *)g;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
}
