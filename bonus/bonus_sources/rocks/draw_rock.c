/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_rock.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 15:47:45 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/02 20:13:13 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../mapgen.h"

void	draw_rock(t_params *prms, unsigned int rock[2])
{
	int	ix;
	int	iy;
	int	m;

	ix = -1;
	iy = -1;
	m = 2;
	prms->map[rock[0]][rock[1]] = '1';
	while (ix <= 1)
	{
		while (iy <= 1)
		{
			if (((ix == 0 || iy == 0) && rand() % m == 1))
			{
				prms->map[rock[0] + ix][rock[1] + iy] = 'R';
				m += 2;
			}
			iy++;
		}
		iy = -1;
		ix++;
	}
	ft_finalize(prms, 'R', '1');
}
