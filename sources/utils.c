/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 15:18:21 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/20 21:17:47 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

void	error(char *errmsg)
{
	ft_putstr_fd("Error\n", 2);
	if (errno == 0)
		ft_putendl_fd(errmsg, 2);
	else
		perror(errmsg);
	exit(EXIT_FAILURE);
}

void	init_array(void *array, size_t len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		((int *)array)[i] = 0;
		i++;
	}
}
