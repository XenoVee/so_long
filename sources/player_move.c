/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_move.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 21:41:00 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/16 21:23:27 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_moveup(t_game *game, int s)
{
	while (s > 0)
	{
		if (collision_north(game, -1, '1'))
		{
			game->plr.speed_y = 0;
			return ;
		}
		*game->plr.y = *game->plr.y - 1;
		s--;
	}
}

void	player_moveleft(t_game *game, int s)
{
	while (s > 0)
	{
		if (collision_west(game, -1, '1'))
		{
			game->plr.speed_x = 0;
			return ;
		}
		*game->plr.x = *game->plr.x - 1;
		s--;
	}
}

void	player_movedown(t_game *game, int s)
{
	while (s > 0)
	{
		if (collision_south(game, 1, '1'))
		{
			game->plr.speed_y = 0;
			return ;
		}
		*game->plr.y = *game->plr.y + 1;
		s--;
	}
}

void	player_moveright(t_game *game, int s)
{
	while (s > 0)
	{
		if (collision_east(game, 1, '1'))
		{
			game->plr.speed_x = 0;
			return ;
		}
		*game->plr.x = *game->plr.x + 1;
		s--;
	}
}

void	movement_input(t_game *game)
{
	int			accel;
	int			max_speed;

	accel = 1;
	max_speed = 3;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT))
		max_speed += 2;
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP)
		&& game->plr.speed_y * -1 < max_speed)
			game->plr.speed_y -= accel;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN)
		&& game->plr.speed_y < max_speed)
			game->plr.speed_y += accel;
	else if (game->plr.speed_y != 0)
		game->plr.speed_y -= ft_sign(game->plr.speed_y);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT)
		&& game->plr.speed_x * -1 < max_speed)
			game->plr.speed_x -= accel;
	else if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT)
		&& game->plr.speed_x < max_speed)
			game->plr.speed_x += accel;
	else if (game->plr.speed_x != 0)
		game->plr.speed_x -= ft_sign(game->plr.speed_x);
}
