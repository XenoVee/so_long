/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   images.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 15:12:50 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/28 18:33:22 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_player(t_player *plr, t_world *wld)
{
	mlx_texture_t	*p_texture;

	// plr->p_img = ft_calloc(1, sizeof(mlx_image_t));
	p_texture = mlx_load_png("/Users/rmaes/Projects/so_long/textures/brick.png");
	plr->p_img = mlx_texture_to_image(wld->mlx, p_texture);
	plr->x = &plr->p_img->instances->x;
	plr->y = &plr->p_img->instances->y;
}

void	create_world(t_world *wld, t_map *map, t_player *plr)
{
	int				ix;
	int				iy;
	mlx_texture_t	*w_texture;

	w_texture = mlx_load_png("/Users/rmaes/Projects/so_long/textures/brick.png");
	wld->w_img = mlx_new_image(wld->mlx, map->x * 17, map->y * 17);
	ix = 0;
	wld->plr = plr;
	while (map->map[ix])
	{
		iy = 0;
		while (map->map[ix][iy])
		{
			if (map->map[ix][iy] == '1')
				mlx_draw_texture(wld->w_img, w_texture, ix * 17, iy * 17);
			iy++;
		}
		ix++;
	}
}

void	images(t_map *map)
{
	t_player	plr;
	t_world		wld;

	wld.mlx = mlx_init(map->y * 17, map->x * 17, "so_long", false);
	if (!wld.mlx)
		error(ERR_MLX_INIT);
	create_world(&wld, map, &plr);
	mlx_image_to_window(wld.mlx, wld.w_img, 0, 0);
	create_player(&plr, &wld);
	mlx_image_to_window(wld.mlx, plr.p_img, map->player[0] * 17, map->player[1] * 17);
	// mlx_loop_hook(wld.mlx, &test, &plr);
	mlx_loop(wld.mlx);
	mlx_terminate(wld.mlx);
}
