/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 15:15:19 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/19 16:01:01 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char	**map;

	errno = 0;
	if (argc != 2)
		error(ERR_FILE);
	else if (check_ext(argv[1]) || ft_strlen(argv[1]) < 4)
		error(ERR_FILE_EXT);
	map = open_file(argv[1]);
	exit(EXIT_SUCCESS);
}
