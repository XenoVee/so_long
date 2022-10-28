/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 21:41:47 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/26 19:00:09 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>

static t_list	*invalid_return(t_map *map, int x, int y)
{
	char	*ret;
	int		errstrlen;
	int		xdigit;
	int		ydigit;

	errstrlen = ft_strlen(ERR_INVALID_CHAR);
	xdigit = ft_digitcount(x);
	ydigit = ft_digitcount(y);
	ret = ft_calloc(sizeof(char), errstrlen + xdigit + ydigit + 14);
	ft_memcpy(ret, ERR_INVALID_CHAR, errstrlen);
	ft_strlcat(ret, " '", errstrlen + 3);
	ret[errstrlen + 2] = map->map[x][y];
	ret[errstrlen + 3] = '\'';
	ft_strlcat(ret, " at [", errstrlen + 10);
	ft_strlcat(ret, ft_itoa(x), errstrlen + 10 + xdigit);
	ft_strlcat(ret, ", ", errstrlen + 12 + xdigit);
	ft_strlcat(ret, ft_itoa(y), errstrlen + 12 + xdigit + ydigit);
	ret[errstrlen + 11 + xdigit + ydigit] = ']';
	return (ft_lstnew(ret));
}

void	count_required(t_err *err, t_map *map, int ix, int iy)
{
	if (map->map[ix][iy] == 'P')
	{
		err->players++;
		if (err->players == 1)
		{
			map->player[0] = ix;
			map->player[1] = iy;
		}
	}
	if (map->map[ix][iy] == 'E')
		err->exits++;
	if (map->map[ix][iy] == 'C')
		err->collect++;
}

// void	count_collect(int collect)

// req[0]: n players
// req[1]: n exits
// req[2]: n collectibles
void	check_map(t_map *map, t_err *err)
{
	unsigned int	ix;
	unsigned int	iy;

	ix = 0;
	iy = 0;
	err->list = ft_lstnew("skip");
	while (map->map[ix])
	{
		while (map->map[ix][iy])
		{
			if (map->map[ix][iy] == 'P' || map->map[ix][iy] == 'E' ||
				map->map[ix][iy] == 'C')
				count_required(err, map, ix, iy);
			if (char_valid(map->map[ix][iy], "01CPE") == 0)
				ft_lstadd_back(&err->list,
					invalid_return(map, ix, iy));
			if (ix == 0 || iy == 0 || ix == map->x - 1 || iy == map->y - 1)
				if (map->map[ix][iy] != '1')
					err->closed++;
			iy++;
		}
		iy = 0;
		ix++;
	}
}

void	error_list(t_err *err)
{
	int	n;

	n = 0;
	if (err->closed != 0)
		multi_error(ERR_ENCLOSED, &n);
	if (err->players != 1)
		multi_error(ERR_PLAYER, &n);
	if (err->exits != 1)
		multi_error(ERR_EXIT, &n);
	if (err->collect < 1)
		multi_error(ERR_NO_COLLECT, &n);
	while (err->list->next)
	{
		if (ft_strncmp(err->list->content, "skip", 4))
			multi_error(err->list->content, &n);
		err->list = err->list->next;
	}
	if (ft_strncmp(err->list->content, "skip", 4))
		multi_error(err->list->content, &n);
	if (n != 0)
		exit(EXIT_FAILURE);
}

void	parsing(t_map *map)
{
	t_err	err;

	null_err(&err);
	check_map(map, &err);
	error_list(&err);
	solve_check(map, &err);
}
