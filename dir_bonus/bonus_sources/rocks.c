/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rocks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 19:24:05 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/02 21:50:20 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"

void	set_limits(int *limx, int *limy, int *ix, int *iy)
{
	*ix = -1 - rand() % 2;
	*iy = -1 - rand() % 2;
	*limx = 3 + *ix;
	*limy = 3 + *iy;
}

int	check_rock(t_params *prms, unsigned int rock[2])
{
	int	ix;
	int	iy;
	int	limy;
	int	limx;

	set_limits(&limx, &limy, &ix, &iy);
	while (iy <= limy)
	{
		while (ix <= limx)
		{
			if (prms->map[ft_btw(rock[0] + ix, prms->x, 0)]
				[ft_btw(rock[1] + iy, prms->y, 0)] == '1')
				return (0);
			if (prms->map[ft_btw(rock[0] + ix, prms->x, 0)]
				[ft_btw(rock[1] + iy, prms->y, 0)] == 'D')
				return (0);
			ix++;
		}
		ix = -2;
		iy++;
	}
	return (1);
}

int	generock(t_params *prms, unsigned int rock[2])
{
	int	l;

	l = 150;
	rock[0] = 2 + (rand() % (prms->x - 4));
	rock[1] = 2 + (rand() % (prms->y - 4));
	while (check_rock(prms, rock) == 0 && l > 0)
	{
		rock[0] = 2 + (rand() % (prms->x - 4));
		rock[1] = 2 + (rand() % (prms->y - 4));
		l--;
	}
	if (l <= 0)
		return (0);
	return (1);
}

void	ft_rocks(t_params *prms, unsigned int nrocks)
{
	unsigned int	rock[2];

	while (nrocks)
	{
		if (generock(prms, rock) == 1)
			draw_rock(prms, rock);
		nrocks--;
	}
}
