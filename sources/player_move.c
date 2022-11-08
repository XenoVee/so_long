/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_move.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 21:41:00 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/08 17:02:12 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_moveup(t_game *game, int s)
{
	int	y;
	int	x[2];

	while (s > 0)
	{
		y = (*game->plr->y - 1) / game->hi;
		x[0] = *game->plr->x / game->wi;
		x[1] = (*game->plr->x - 1 + game->plr->p_img->width)
			/ game->wi;
		while (x[0] <= x[1])
		{
			if (game->map->map[y][x[0]] == '1')
				return ;
			x[0]++;
		}
		*game->plr->y = *game->plr->y - 1;
		s--;
	}
}

void	player_moveleft(t_game *game, int s)
{
	int	y[2];
	int	x;

	while (s > 0)
	{
		x = (*game->plr->x -1) / game->wi;
		y[0] = *game->plr->y / game->hi;
		y[1] = (*game->plr->y - 1 + game->plr->p_img->height)
			/ game->hi;
		while (y[0] <= y[1])
		{
			if (game->map->map[y[0]][x] == '1')
				return ;
			y[0]++;
		}
		*game->plr->x = *game->plr->x - 1;
		s--;
	}
}

void	player_movedown(t_game *game, int s)
{
	int	y;
	int	x[2];

	while (s > 0)
	{
		y = (*game->plr->y + game->plr->p_img->height)
			/ game->hi;
		x[0] = *game->plr->x / game->wi;
		x[1] = ((*game->plr->x - 1) + game->plr->p_img->width)
			/ game->wi ;
		ft_printf("player pos pixels %i, %i\n", *game->plr->y, *game->plr->x);
		ft_printf("sprite x y %i, %i\n", game->hi, game->wi);
		ft_printf("check x y %i, %i\n", x[0], y);
		ft_printf("map x, map y %i, %i\n", game->map->x, game->map->y);
		ft_printf("%c\n", game->map->map[y][x[0]]);
		while (x[0] <= x[1])
		{
			if (game->map->map[y][x[0]] == '1')
				return ;
			x[0]++;
		}
		*game->plr->y = *game->plr->y + 1;
		s--;
	}
}

void	player_moveright(t_game *game, int s)
{
	int	y[2];
	int	x;

	while (s > 0)
	{
		x = (*game->plr->x + game->plr->p_img->width)
			/ game->wi;
		y[0] = *game->plr->y / game->hi;
		y[1] = (*game->plr->y - 1 + game->plr->p_img->height)
			/ game->hi;
		while (y[0] <= y[1])
		{
			if (game->map->map[y[0]][x] == '1')
				return ;
			y[0]++;
		}
		*game->plr->x = *game->plr->x + 1;
		s--;
	}
}
