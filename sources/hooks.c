/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 20:55:06 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/14 18:14:34 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	movement_input(t_game *game)
{
	int			accel;
	int			max_accel;

	accel = 2;
	max_accel = 4;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT))
	{
		accel *= 2;
		max_accel *= 2;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP)
		&& game->plr.speed_y * -1 < max_accel)
			game->plr.speed_y -= accel;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN)
		&& game->plr.speed_y < max_accel)
			game->plr.speed_y += accel;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT)
		&& game->plr.speed_x * -1 < max_accel)
			game->plr.speed_x -= accel;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT)
		&& game->plr.speed_x < max_accel)
			game->plr.speed_x += accel;
}

// void	player_anim(t_game *game, int dir_x, int dir_y)
// {

// }

void	move_hook(void *g)
{
	t_game		*game;

	game = (t_game *)g;
	movement_input(game);
	if (game->plr.speed_x < 0)
		player_moveleft(game, game->plr.speed_x * -1);
	if (game->plr.speed_y < 0)
		player_moveup(game, game->plr.speed_y * -1);
	if (game->plr.speed_x > 0)
		player_moveright(game, game->plr.speed_x);
	if (game->plr.speed_y > 0)
		player_movedown(game, game->plr.speed_y);
	if (game->plr.speed_y != 0)
		game->plr.speed_y -= ft_sign(game->plr.speed_y);
	if (game->plr.speed_x != 0)
		game->plr.speed_x -= ft_sign(game->plr.speed_x);
}

void	exit_hook(void *g)
{
	t_game		*game;

	game = (t_game *)g;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
}
