/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 17:48:29 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/08 17:05:41 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int	read_compare_line(t_map *map, int strl[2], int i, int fd)
{
	map->map[i] = get_next_line(fd);
	if (map->map[i] == NULL)
		return (i + 1);
	strl[i % 2] = ft_strlen(map->map[i]);
	if (map->map[i][strl[i % 2] - 1] == '\n')
	{
		map->map[i][strl[i % 2] - 1] = '\0';
		strl[i % 2]--;
	}
	if (strl[(i + 1) % 2] != strl[i % 2] && i != 0)
		error(ERR_MAP_RECT);
	map->y = strl[i % 2];
	ft_printf("map y: %i\n", map->y);
	return (i + 1);
}

void	open_file(char *filepath, t_map *map)
{
	int		fd;
	int		strl[2];
	int		i;

	i = 0;
	strl[1] = 0;
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		error(ERR_FD);
	map->map = ft_calloc(sizeof(char *), i + 1);
	i = read_compare_line(map, strl, i, fd);
	while (map->map[i - 1] != NULL)
	{
		map->map = ft_realloc(map->map, sizeof(char *) * (i + 1));
		i = read_compare_line(map, strl, i, fd);
	}
	map->x = i - 1;
	ft_printf("map x: %i\n", map->x);
	close(fd);
}
