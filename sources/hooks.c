/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 20:55:06 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/28 18:26:10 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	write_moves(game);
	player_anim(&game->plr, game->mlx, ft_sign(game->plr.speed_x),
		ft_sign(game->plr.speed_y));
}

void	exit_hook(void *g)
{
	t_game		*game;

	game = (t_game *)g;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
}
