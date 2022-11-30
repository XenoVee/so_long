/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 20:55:06 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/30 14:49:00 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "stdlib.h"

void	anim_exit_hook(void *g)
{
	t_game		*game;
	static int	frame = 0;

	game = (t_game *)g;
	if (game->exit.active == true)
	{
		mlx_draw_texture(game->exit.e_img,
			game->exit.op_text[frame / 5], 0, 0);
		frame++;
		if (frame / 5 > 4)
			frame = 0;
	}
}

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
	write_moves(game, false);
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
