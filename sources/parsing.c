/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 17:11:41 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/20 18:15:05 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_enclosed(t_map *map)
{
	int	ix;
	int	iy;

	ix = 0;
	iy = 0;
	while (map->map[ix])
	{
		while (map->map[ix][iy])
		{
			char_valid(map->map[ix][iy], "01");
			if (ix == 0 || iy == 0 || ix == map->x - 1 || iy == map->y - 1)
				if (map->map[ix][iy] != '1')
					error(ERR_ENCLOSED);
			iy++;
		}
		iy = 0;
		ix++;
	}
}

char	*invalid_char_return(t_map *map, int x, int y)
{
	char	*ret;
	int		errstlen;

	errstlen = ft_strlen(ERR_INVALID_CHAR)

	ret = ft_calloc(sizeof(char), errstrlen);
	ft_memcpy(ret, ERR_INVALID_CHAR, errstrlen);
	ft_realloc(ret, errstlen +)
	return (ret);
}

void	char_valid(char c, char *v_chars)
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
		error(ft_strlcat(ERR_INVALID_CHAR, ": loc", 5));
}

void	parsing(t_map *map)
{
	check_enclosed(map);
}
