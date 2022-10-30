/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_move.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/30 21:41:00 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/30 22:25:11 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_moveup(t_game *game)
{
	if (game->map->map[*game->plr->y / 20 - 1][*game->plr->x / 20] != '1')
	{
		*game->plr->y = *game->plr->y - 2;
	}
}

void	player_movedown(t_game *game)
{
	if (game->map->map[*game->plr->y / 20 + 1][*game->plr->x / 20] != '1')
	{
		*game->plr->y = *game->plr->y + 2;
	}
}

void	player_moveleft(t_game *game)
{
	if (game->map->map[*game->plr->y / 20][*game->plr->x / 20 - 1] != '1')
	{
		*game->plr->x = *game->plr->x - 2;
	}
}

void	player_moveright(t_game *game)
{
	if (game->map->map[*game->plr->y / 20][*game->plr->x / 20 + 1] != '1')
	{
		*game->plr->x = *game->plr->x + 2;
	}
}
