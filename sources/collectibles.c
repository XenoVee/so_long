/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collectibles.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 21:00:30 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/29 14:25:20 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	collected(t_game *game, int x, int y, int i)
{
	game->map->map[x][y] = '0';
	game->coll.c_img->instances[i].enabled = false;
	game->map->ncollect--;
	if (game->map->ncollect <= 0)
		game->exit.active = true;
}

void	found_collectible(t_game *game)
{
	int	x[2];
	int	y[2];
	int	i;

	x[0] = *game->plr.x / game->wi;
	x[1] = (*game->plr.x - 1 + game->plr.p_img->width) / game->wi;
	y[0] = *game->plr.y / game->hi;
	y[1] = (*game->plr.y - 1 + game->plr.p_img->height) / game->hi;
	i = 0;
	while (game->coll.inst[i])
	{
		if (x[0] <= game->coll.inst[i][1] && x[1] >= game->coll.inst[i][1])
		{
			if (y[0] <= game->coll.inst[i][2] && y[1] >= game->coll.inst[i][2])
			{
				collected(game, game->coll.inst[i][2],
					game->coll.inst[i][1], i);
				return ;
			}
		}
		i++;
	}
}

void	put_collectible(t_game *game, int ix, int iy)
{
	static int	i = 0;

	game->coll.inst[i] = ft_calloc(sizeof(int *), 4);
	if (game->coll.inst[i] == NULL)
		error(ERR_MALLOC);
	game->coll.inst[i][0] = mlx_image_to_window
		(game->mlx, game->coll.c_img, iy * game->hi, ix * game->wi);
	game->coll.inst[i][1] = iy;
	game->coll.inst[i][2] = ix;
	game->coll.inst[i][3] = 0;
	i++;
}

void	create_collectibles(t_game *game, char **map)
{
	int	ix;
	int	iy;

	ix = 0;
	game->coll.c_text = mlx_load_png("textures/gem.png");
	game->coll.c_img = mlx_texture_to_image(game->mlx, game->coll.c_text);
	game->coll.inst = ft_calloc(sizeof(int *), game->map->ncollect + 1);
	game->coll.inst[game->map->ncollect] = NULL;
	while (map[ix])
	{
		iy = 0;
		while (map[ix][iy])
		{
			if (map[ix][iy] == 'C')
			{
				put_collectible(game, ix, iy);
			}
			iy++;
		}
		ix++;
	}
}
