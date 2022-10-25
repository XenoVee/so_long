/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 19:15:02 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/25 22:28:00 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	copy_map(t_map *dst, t_map *src)
{
	int	ix;
	int	iy;

	dst->x = src->x;
	dst->y = src->y;
	dst->player[0] = src->player[0];
	dst->player[1] = src->player[1];
	ix = 0;
	iy = 0;
	dst->map = ft_calloc(sizeof(char *), src->x);
	while (src->map[ix])
	{
		dst->map[ix] = ft_calloc(sizeof(char), src->y);
		while (src->map[ix][iy])
		{
			dst->map[ix][iy] = src->map[ix][iy];
			iy++;
		}
		iy = 0;
		ix ++;
	}
}

void	solve(t_map *map, int ix, int iy, t_err *found)
{
	if (map->map[ix][iy] == 'E')
		found->exits++;
	if (map->map[ix][iy] == 'C')
		found->collect++;
	map->map[ix][iy] = '1';
	if (map->map[ix + 1][iy] != '1')
		solve(map, ix + 1, iy, found);
	if (map->map[ix - 1][iy] != '1')
		solve(map, ix - 1, iy, found);
	if (map->map[ix][iy + 1] != '1')
		solve(map, ix, iy + 1, found);
	if (map->map[ix][iy - 1] != '1')
		solve(map, ix, iy - 1, found);
}

void	solve_check(t_map *map, t_err *err)
{
	t_map	tempmap;
	t_err	found;

	found.exits = 0;
	found.collect = 0;
	copy_map(&tempmap, map);
	solve(&tempmap, tempmap.player[0], tempmap.player[1], &found);
	if (found.exits != 1 || found.collect != err->collect)
		error(ERR_SOLVE);
}
