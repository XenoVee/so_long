/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rooms_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 17:46:54 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/02 21:50:16 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"

static int	check_wall_2(unsigned int sta[2], unsigned int end[2],
							t_params *prms, int w)
{
	unsigned int	i;

	if (sta[0] != end[0] && sta[1] == end[1])
	{
		i = sta[0];
		while (i < end[0] && prms->map[i][sta[1]] == '0'
			&& prms->map[i][sta[1] + w] == '0')
			i++;
		while (i < end[0]
			&& (prms->map[i][sta[1]] != '0' || prms->map[i][sta[1] + w] != '0'))
			i++;
		if (i < end[0] && prms->map[i][sta[1]] == '0'
			&& prms->map[i][sta[1] + w] == '0')
			return (2);
		else if (i <= end[0] && prms->map[i][sta[1]] != '0'
			&& prms->map[i][sta[1] + w] != '0')
			return (1);
	}
	return (0);
}

static int	check_wall_1(unsigned int sta[2], unsigned int end[2],
							t_params *prms, int w)
{
	unsigned int	i;

	if (sta[0] == end[0] && sta[1] != end[1])
	{
		i = sta[1];
		while (i < end[1] && prms->map[sta[0]][i] == '0'
			&& prms->map[sta[0] + w][i] == '0')
			i++;
		while (i < end[1]
			&& (prms->map[sta[0]][i] != '0' || prms->map[sta[0] + w][i] != '0'))
			i++;
		if (i < end[1] && prms->map[sta[0]][i] == '0'
			&& prms->map[sta[0] + w][i] == '0')
			return (2);
		else if (i <= end[1] && prms->map[sta[0]][i] != '0'
			&& prms->map[sta[0] + w][i] != '0')
			return (1);
	}
	return (0);
}

static int	check_interrupted(unsigned int room[2][2], t_params *prms)
{
	unsigned int	ocorner[2][2];

	ocorner[0][0] = room[1][0];
	ocorner[0][1] = room[0][1];
	ocorner[1][0] = room[0][0];
	ocorner[1][1] = room[1][1];
	if (check_wall_1(room[0], ocorner[1], prms, +1)
		+ check_wall_1(ocorner[0], room[1], prms, -1) >= 3)
		return (0);
	if (check_wall_2(room[0], ocorner[0], prms, +1)
		+ check_wall_2(ocorner[1], room[1], prms, -1) >= 3)
		return (0);
	return (1);
}

static int	check_space_ext(int c, int d,
	unsigned int room[2][2], t_params *prms)
{
	int	ix;
	int	iy;

	iy = -1;
	ix = -1;
	while (iy < 2)
	{
		while (ix < 2)
		{
			if (prms->map[ft_btw(room[0 + c][0] + ix, prms->x, 0)]
					[ft_btw(room[0 + d][1] + iy, prms->y, 0)] == '1')
				return (0);
			ix++;
		}
		ix = -2;
		iy++;
	}
	return (1);
}

int	check_space(unsigned int room[2][2], t_params *prms)
{
	int	c;
	int	d;

	c = 0;
	d = 0;
	while (c < 2)
	{
		while (d < 2)
		{
			if (!check_space_ext(c, d, room, prms))
				return (0);
			d++;
		}
		d = 0;
		c++;
	}
	if (!check_interrupted(room, prms))
		return (0);
	return (1);
}
