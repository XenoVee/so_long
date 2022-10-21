/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 17:11:41 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/20 21:28:27 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	invalid_char_return(t_map *map, int x, int y)
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
	error(ret);
}

void	count_required(int req[3], char c, int final)
{
	if (c == 'P')
	{
		if (req[0] >= 1)
			error(ERR_MORE_PLAYERS);
		req[0]++;
	}
	if (c == 'E')
	{
		if (req[1] >= 1)
			error(ERR_MORE_EXITS);
		req[1]++;
	}
	if (c == 'C')
		req[2]++;
	if (final == 1)
	{
		if (req[0] == 0)
			error(ERR_NO_PLAYER);
		if (req[0] == 0)
			error(ERR_NO_EXIT);
		if (req[0] == 0)
			error(ERR_NO_COLLECT);
	}
}

// void	count_collect(int collect)

// req[0]: n players
// req[1]: n exits
// req[2]: n collectibles
void	check_map(t_map *map)
{
	int	ix;
	int	iy;
	int	req[3];

	ix = 0;
	iy = 0;
	init_array(req, 3);
	while (map->map[ix])
	{
		while (map->map[ix][iy])
		{
			if (map->map[ix][iy] == 'P' || map->map[ix][iy] == 'E' ||
				map->map[ix][iy] == 'C')
				count_required(req, map->map[ix][iy], 0);
			if (char_valid(map->map[ix][iy], "01CPE") == 0)
				invalid_char_return(map, ix, iy);
			if (ix == 0 || iy == 0 || ix == map->x - 1 || iy == map->y - 1)
				if (map->map[ix][iy] != '1')
					error(ERR_ENCLOSED);
			iy++;
		}
		iy = 0;
		ix++;
	}
	count_required(req, '0', 1);
}

int	char_valid(char c, char *v_chars)
{
	int	i;
	int	valid;

	i = 0;
	valid = 0;
	while (v_chars[i] && valid != 1)
	{
		if (c == v_chars[i])
			valid = 1;
		i++;
	}
	if (valid != 1)
		return (0);
	return (1);
}

void	parsing(t_map *map)
{
	check_map(map);
}
