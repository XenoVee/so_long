/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/19 19:43:42 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/02 21:16:13 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"

void	ft_print_map(t_params *prms)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (prms->map[x][y] != 0)
	{
		while (prms->map[x])
		{
			if (prms->map[x][y] != '0')
				write(1, &prms->map[x][y], 1);
			else
				write(1, " ", 1);
			x++;
		}
		write(1, "\n", 1);
		x = 0;
		y++;
	}
}
