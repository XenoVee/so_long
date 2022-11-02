/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rooms_draw.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/22 18:53:04 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/14 17:02:01 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../mapgen.h"

static int	ft_draw_walls(t_params *prms, unsigned int room[2][2],
	unsigned int ix, unsigned int iy)
{
	if (prms->map[ix][iy] == '0')
	{
		if (ix == room[0][0] || ix == room[1][0]
			|| iy == room[1][1] || iy == room[0][1])
		{
			prms->map[ix][iy] = 'W';
			return (1);
		}
	}
	return (0);
}

static void	ft_draw_infill(t_params *prms, unsigned int room[2][2],
	unsigned int ix, unsigned int iy)
{
	if ((ix > room[0][0] && iy > room[0][1])
		&& (ix < room[1][0] && iy < room[1][1])
		&& !(ix >= prms->x || iy >= prms->y))
		if (prms->map[ix][iy] == '0')
			prms->map[ix][iy] = 'T';
}

void	ft_draw_room(unsigned int room[2][2], t_params *prms)
{
	int				f;
	unsigned int	ix;
	unsigned int	iy;

	f = 0;
	ix = room[0][0];
	iy = room[0][1];
	while (ix - 1 != room[1][0] || iy != room[1][1])
	{
		f += ft_draw_walls(prms, room, ix, iy);
		ft_draw_infill(prms, room, ix, iy);
		if (ix == room[1][0] && iy < room[1][1])
		{
			ix = room[0][0];
			iy++;
		}
		else
			ix++;
	}
	if (f > 0)
		ft_draw_door(prms, room);
	ft_finalize(prms, 'W', '1');
}
