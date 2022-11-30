/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 15:12:50 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/30 17:14:22 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <unistd.h>
#include <stdlib.h>

int	write_moves(t_game *game, bool ret)
{
	static mlx_image_t	*text = NULL;
	static int			moves = 0;
	char				*itoa;

	if (ret == false)
	{
		if (text != NULL)
			mlx_delete_image(game->mlx, text);
		itoa = ft_itoa(moves / game->wi);
		text = mlx_put_string(game->mlx, itoa, 1, 1);
		free (itoa);
		moves += ft_abs(game->plr.speed_x) + ft_abs(game->plr.speed_y);
	}
	return (moves / game->wi);
}

void	write_score(t_game *game)
{
	static int			score = 0;
	static int			moves = 0;
	static mlx_image_t	*text = NULL;
	char				*itoa;

	if (text != NULL)
		mlx_delete_image(game->mlx, text);
	score += ft_btw
		(120 - (2 * ft_max(1, write_moves(game, true) - moves)), 10, 100);
	itoa = ft_itoa(score);
	text = mlx_put_string(game->mlx, itoa,
			game->mlx->width - ft_digitcount(score) * 10 - 1, 1);
	free (itoa);
	moves = write_moves(game, true);
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
	mlx_loop_hook(game.mlx, &anim_exit_hook, &game);
	mlx_loop(game.mlx);
	free_things(&game);
	mlx_terminate(game.mlx);
}
