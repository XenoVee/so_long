/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 17:48:29 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/20 16:38:40 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <fcntl.h>
#include <stdlib.h>

static int	read_compare_line(char **map, int strl[2], int i, int fd)
{
	char	*line;

	line = get_next_line(fd);
	map[i] = line;
	strl[i % 2] = ft_strlen(map[i]);
	if (strl[(i + 1) % 2] != strl[i % 2] && i != 0)
		error(ERR_MAP_RECT);
	return (i + 1);
}

char	**open_file(char *filepath)
{
	int		fd;
	char	**map;
	int		strl[2];
	int		i;

	i = 0;
	strl[1] = 0;
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		error(ERR_FD);
	map = ft_calloc(sizeof(char *), i + 1);
	ft_printf("%d", i);
	i = read_compare_line(map, strl, i, fd);
	ft_printf("%d, %s", i, map[i - 1]);
	while (map[i - 1] != NULL)
	{
		map = ft_realloc(map, sizeof(char *) * i + 1);
		i = read_compare_line(map, strl, i, fd);
		ft_printf("%d, %s", i, map[i - 1]);
	}
	return (NULL);
}
