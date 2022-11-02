/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fill_map.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/19 19:43:42 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/02 21:17:20 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"
#include <math.h>

void	ft_cleanup(t_params *prms)
{
	unsigned int	ix;
	unsigned int	iy;

	ix = 0;
	iy = 0;
	while (prms->map[ix])
	{
		while (prms->map[ix][iy])
		{
			if (prms->map[ix][iy] == 'T')
				prms->map[ix][iy] = '0';
			if (prms->map[ix][iy] == 'D')
				prms->map[ix][iy] = '0';
			iy++;
		}
		ix++;
		iy = 0;
	}
}

void	ft_outer_walls(t_params *prms)
{
	unsigned int	ix;
	unsigned int	iy;

	ix = 0;
	iy = 0;
	while (prms->map[ix])
	{
		while (prms->map[ix][iy])
		{
			if (ix == 0 || iy == 0 || prms->map[ix + 1] == NULL
				|| prms->map[ix][iy + 1] == 0)
				prms->map[ix][iy] = '1';
			iy++;
		}
	ix++;
	iy = 0;
	}
}

void	ft_fill_map(t_params *prms)
{	
	ft_outer_walls(prms);
	if (prms->y > 8 && prms->x > 8)
		ft_rooms(prms, 3 + rand() % ft_min(prms->size / 5, 10));
	if (prms->y > 5 && prms->x > 5)
		ft_rocks(prms, 1 + rand() % (prms->size / 4));
	ft_cleanup(prms);
	ft_collectibles(prms, 1 + rand() % ((ft_max(prms->size, 5) + 1) / 5));
	put_thing(prms, 'P');
	put_thing(prms, 'E');
}
