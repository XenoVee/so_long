/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 15:15:19 by rmaes         #+#    #+#                 */
/*   Updated: 2023/04/07 19:40:40 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>

void	leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_map	map;

	// atexit(leaks);
	errno = 0;
	if (argc != 2)
		error(ERR_FILE);
	else if (check_ext(argv[1]) || ft_strlen(argv[1]) < 4)
		error(ERR_FILE_EXT);
	open_file(argv[1], &map);
	parsing(&map);
	window(&map);
	// exit(EXIT_SUCCESS);
	return (0);
}
