/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collision.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 20:32:50 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/16 21:16:05 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	collision_north(t_game *game, int offset, char c)
{
	int	y;
	int	x[2];

	y = (*game->plr.y + offset) / game->hi;
	x[0] = *game->plr.x / game->wi;
	x[1] = (*game->plr.x - 1 + game->plr.p_img->width)
		/ game->wi;
	while (x[0] <= x[1])
	{
		if (game->map->map[y][x[0]] == c)
			return (1);
		x[0]++;
	}
	return (0);
}

int	collision_east(t_game *game, int offset, char c)
{
	int	y[2];
	int	x;

	offset++;
	x = (*game->plr.x + game->plr.p_img->width - 1 + offset)
		/ game->wi;
	y[0] = *game->plr.y / game->hi;
	y[1] = (*game->plr.y - 1 + game->plr.p_img->height)
		/ game->hi;
	while (y[0] <= y[1])
	{
		if (game->map->map[y[0]][x] == c)
			return (1);
		y[0]++;
	}
	return (0);
}

int	collision_south(t_game *game, int offset, char c)
{
	int	y;
	int	x[2];

	offset++;
	y = (*game->plr.y + game->plr.p_img->height - 1 + offset)
		/ game->hi;
	x[0] = (*game->plr.x) / game->wi;
	x[1] = (*game->plr.x - 1 + game->plr.p_img->width)
		/ game->wi ;
	while (x[0] <= x[1])
	{
		if (game->map->map[y][x[0]] == c)
			return (1);
		x[0]++;
	}
	return (0);
}

int	collision_west(t_game *game, int offset, char c)
{
	int	y[2];
	int	x;

	x = (*game->plr.x + offset) / game->wi;
	y[0] = *game->plr.y / game->hi;
	y[1] = (*game->plr.y - 1 + game->plr.p_img->height)
		/ game->hi;
	while (y[0] <= y[1])
	{
		if (game->map->map[y[0]][x] == c)
			return (1);
		y[0]++;
	}
	return (0);
}
