/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   doors.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/28 16:33:51 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/02 21:50:35 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"

static void	ft_generate_door(unsigned int door[2], unsigned int room[2][2]
	, unsigned int width, unsigned int height)
{
	unsigned int	loc;

	loc = 1 + rand() % (((width + height) * 2) - 1);
	if (loc > (width * 2) + height)
	{
		door[0] = room[0][0];
		door[1] = room[1][1] - (loc - (width * 2) - height -1);
	}
	else if (loc > width + height)
	{
		door[0] = room[1][0] - (loc - width - height - 1);
		door[1] = room[1][1];
	}
	else if (loc > width)
	{
		door[0] = room[1][0];
		door[1] = room[0][1] + loc - width - 1;
	}
	else if (loc <= width)
	{
		door[0] = room[0][0] + loc - 1;
		door[1] = room[0][1];
	}
}

static int	ft_door_valid(t_params *prms, unsigned int door[2])
{
	int	t;

	t = 0;
	if (prms->map[door[0]][door[1]] == 'W')
	{
		if (prms->map[door[0] + 1][door[1]] == 'W')
			if (prms->map[door[0] - 1][door[1]] == 'W')
				t += 2;
		if (prms->map[door[0]][door[1] + 1] == 'W')
			if (prms->map[door[0]][door[1] - 1] == 'W')
				t += 2;
	}
	if (t == 2)
		return (1);
	return (0);
}

static void	ft_put_door(t_params *prms, unsigned int door[2])
{
	int	i;

	i = -1;
	prms->map[door[0]][door[1]] = 'T';
	while (i < 2)
	{
		if (prms->map[door[0] + i][door[1]] != 'W')
			prms->map[door[0] + i][door[1]] = 'D';
		if (prms->map[door[0]][door[1] + i] != 'W')
			prms->map[door[0]][door[1] + i] = 'D';
		i++;
	}
}

void	ft_draw_door(t_params *prms, unsigned int room[2][2])
{
	unsigned int	door[2];
	unsigned int	width;
	unsigned int	height;

	width = room[1][0] - room[0][0];
	height = room[1][1] - room[0][1];
	while (width != 0)
	{
		ft_generate_door(door, room, width, height);
		if (ft_door_valid(prms, door) == 1)
		{
			ft_put_door(prms, door);
			width = 0;
		}
	}
}
