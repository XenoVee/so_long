/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_move.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 21:41:00 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/07 18:33:39 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_moveup(t_game *game, int s)
{
	int	y;
	int	x[2];

	while (s > 0)
	{
		y = (*game->plr->y - 1) / game->wld->wall_text->height;
		x[0] = *game->plr->x / game->wld->wall_text->width;
		x[1] = (*game->plr->x - 1 + game->plr->p_img->width)
			/ game->wld->wall_text->width;
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
		x = (*game->plr->x -1) / game->wld->wall_text->width;
		y[0] = *game->plr->y / game->wld->wall_text->height;
		y[1] = (*game->plr->y - 1 + game->plr->p_img->height)
			/ game->wld->wall_text->height;
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
			/ game->wld->wall_text->height;
		x[0] = *game->plr->x / game->wld->wall_text->width;
		x[1] = ((*game->plr->x - 1) + game->plr->p_img->width)
			/ game->wld->wall_text->width ;
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
			/ game->wld->wall_text->width;
		y[0] = *game->plr->y / game->wld->wall_text->height;
		y[1] = (*game->plr->y - 1 + game->plr->p_img->height)
			/ game->wld->wall_text->height;
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
