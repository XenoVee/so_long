/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 15:18:21 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/09 18:23:55 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>

void	error(char *errmsg)
{
	ft_putstr_fd("Error\n", 2);
	if (errno == 0)
		ft_putendl_fd(errmsg, 2);
	else
		perror(errmsg);
	exit(EXIT_FAILURE);
}

void	multi_error(char *errmsg, int *n)
{
	if (*n == 0)
		ft_putstr_fd("Error\n", 2);
	if (errno == 0)
		ft_putendl_fd(errmsg, 2);
	else
		perror(errmsg);
	*n = *n + 1;
}

void	null_err(t_err *err)
{
	err->players = 0;
	err->exits = 0;
	err->collect = 0;
	err->closed = 0;
}

void	shift_buf(char *buf)
{
	int	i;

	i = 1;
	while (buf[i - 1])
	{
		buf[i - 1] = buf[i];
		i++;
	}
}

void	read_buf(int fd, char *buf, int nbyte)
{
	if (read(fd, buf, nbyte) == -1)
		error(ERR_READ_RAND);
	buf[19] = '\0';
}
