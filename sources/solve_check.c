/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 19:15:02 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/29 18:35:17 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>

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
	dst->map = ft_calloc(sizeof(char *), src->x + 1);
	while (src->map[ix])
	{
		dst->map[ix] = ft_calloc(sizeof(char), src->y + 1);
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

static char	*unreachable_return(t_err *found, int x, int y)
{
	char	*ret;
	int		errstrlen;
	int		xdigit;
	int		ydigit;

	errstrlen = ft_strlen(ERR_SOLVE_COLLECT);
	xdigit = ft_digitcount(x);
	ydigit = ft_digitcount(y);
	ret = ft_calloc(sizeof(char), errstrlen + xdigit + ydigit + 14);
	ft_memcpy(ret, ERR_SOLVE_COLLECT, errstrlen);
	ft_strlcat(ret, "[", errstrlen + 2);
	ft_strlcat(ret, ft_itoa(x), errstrlen + 2 + xdigit);
	ft_strlcat(ret, ", ", errstrlen + 4 + xdigit);
	ft_strlcat(ret, ft_itoa(y), errstrlen + 4 + xdigit + ydigit);
	ret[errstrlen + 3 + xdigit + ydigit] = ']';
	found->collect++;
	return (ret);
}

void	solved_errors(t_err *found, t_err *err, t_map *map)
{
	int	n;
	int	ix;
	int	iy;

	n = 0;
	ix = 0;
	if (found->exits != 1 || found->collect != err->collect)
		multi_error(ERR_SOLVE, &n);
	if (found->exits != 1)
		multi_error(ERR_SOLVE_EXIT, &n);
	while (found->collect != err->collect && map->map[ix])
	{
		iy = 0;
		while (map->map[ix][iy])
		{
			if (map->map[ix][iy] == 'C')
				multi_error(unreachable_return(found, ix, iy), &n);
			iy++;
		}
		ix++;
	}
	if (n != 0)
		exit(EXIT_FAILURE);
}

void	solve_check(t_map *map, t_err *err)
{
	t_map	tempmap;
	t_err	found;

	found.exits = 0;
	found.collect = 0;
	copy_map(&tempmap, map);
	solve(&tempmap, tempmap.player[0], tempmap.player[1], &found);
	solved_errors(&found, err, &tempmap);
}
