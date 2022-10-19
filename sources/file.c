/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 17:48:29 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/18 17:59:09 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <fcntl.h>

int	open_file(char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		error(ERR_FD);
	return (fd);
}
