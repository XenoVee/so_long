/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_move.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 21:41:00 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/02 22:29:18 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_moveup(t_game *game)
{
	int	y;
	int	x[2];

	y = (*game->plr->y - 1) / game->wld->w_text->height;
	x[0] = *game->plr->x / game->wld->w_text->width;
	x[1] = (*game->plr->x - 1 + game->plr->p_img->width)
		/ game->wld->w_text->width ;
	while (x[0] <= x[1])
	{
		if (game->map->map[y][x[0]] == '1')
			return ;
		x[0]++;
	}
	*game->plr->y = *game->plr->y - 1;
}

void	player_moveleft(t_game *game)
{
	int	y[2];
	int	x;

	x = (*game->plr->x -1) / game->wld->w_text->width;
	y[0] = *game->plr->y / game->wld->w_text->height;
	y[1] = (*game->plr->y - 1 + game->plr->p_img->height)
		/ game->wld->w_text->height;
	while (y[0] <= y[1])
	{
		if (game->map->map[y[0]][x] == '1')
			return ;
		y[0]++;
	}
	*game->plr->x = *game->plr->x - 1;
}

void	player_movedown(t_game *game)
{
	int	y;
	int	x[2];

	y = (*game->plr->y + game->plr->p_img->height)
		/ game->wld->w_text->height;
	x[0] = *game->plr->x / game->wld->w_text->width;
	x[1] = ((*game->plr->x - 1) + game->plr->p_img->width)
		/ game->wld->w_text->width ;
	while (x[0] <= x[1])
	{
		if (game->map->map[y][x[0]] == '1')
			return ;
		x[0]++;
	}
	*game->plr->y = *game->plr->y + 1;
}

void	player_moveright(t_game *game)
{
	int	y[2];
	int	x;

	x = (*game->plr->x + game->plr->p_img->width)
		/ game->wld->w_text->width;
	y[0] = *game->plr->y / game->wld->w_text->height;
	y[1] = (*game->plr->y - 1 + game->plr->p_img->height)
		/ game->wld->w_text->height;
	while (y[0] <= y[1])
	{
		if (game->map->map[y[0]][x] == '1')
			return ;
		y[0]++;
	}
	*game->plr->x = *game->plr->x + 1;
}
