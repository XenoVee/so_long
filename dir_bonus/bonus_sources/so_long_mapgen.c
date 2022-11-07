/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long_mapgen.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 15:15:19 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/03 15:57:03 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_map			map;

	errno = 0;
	if (argc == 2)
	{
		if (check_ext(argv[1]) || ft_strlen(argv[1]) < 4)
			error(ERR_FILE_EXT);
		open_file(argv[1], &map);
	}
	else
		mapgen(argc, argv, &map);
	parsing(&map);
	images(&map);
	exit(EXIT_SUCCESS);
}
