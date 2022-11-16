/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 20:55:06 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/15 19:48:09 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	player_anim(t_player *plr, mlx_t *mlx, int dir_x, int dir_y)
{
	static int	frame = 0;
	int			fpause;

	fpause = 10;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_SHIFT))
		fpause = 6;
	if (dir_x == 1 && dir_y == 0)
		mlx_draw_texture(plr->p_img, plr->p_text[right][frame / fpause], 0, 0);
	if (dir_x == -1 && dir_y == 0)
		mlx_draw_texture(plr->p_img, plr->p_text[left][frame / fpause], 0, 0);
	if (dir_x == 0 && dir_y == -1)
		mlx_draw_texture(plr->p_img, plr->p_text[up][frame / fpause], 0, 0);
	if (dir_x == 0 && dir_y == 1)
		mlx_draw_texture(plr->p_img, plr->p_text[down][frame / fpause], 0, 0);
	if (dir_x == 1 && dir_y == -1)
		mlx_draw_texture(plr->p_img, plr->p_text[up_r][frame / fpause], 0, 0);
	if (dir_x == 1 && dir_y == 1)
		mlx_draw_texture(plr->p_img, plr->p_text[down_r][frame / fpause], 0, 0);
	if (dir_x == -1 && dir_y == -1)
		mlx_draw_texture(plr->p_img, plr->p_text[up_l][frame / fpause], 0, 0);
	if (dir_x == -1 && dir_y == 1)
		mlx_draw_texture(plr->p_img, plr->p_text[down_l][frame / fpause], 0, 0);
	frame++;
	if (frame >= fpause * 4)
		frame = 0;
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
