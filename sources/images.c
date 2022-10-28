/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   images.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 15:12:50 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/28 22:41:11 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "unistd.h"

void	test(void *wld)
{
	t_player	*play;

	play = ((t_world *)wld)->plr;
	if (mlx_is_key_down(((t_world *)wld)->mlx, MLX_KEY_UP)
		play->x = play->x + 2;
	if (mlx_is_key_down(((t_world *)wld)->mlx, MLX_KEY_DOWN)
		play->x = play->x - 2;
	if (mlx_is_key_down(((t_world *)wld)->mlx, MLX_KEY_LEFT)
		play->x = play->y - 2;
	if (mlx_is_key_down(((t_world *)wld)->mlx, MLX_KEY_RIGHT)
		play->y = play->y + 2;
}

void	create_player(t_player *plr, t_world *wld)
{
	mlx_texture_t	*p_texture;

	p_texture = mlx_load_png
		("/Users/rmaes/Projects/so_long/textures/brick.png");
	plr->p_img = mlx_texture_to_image(wld->mlx, p_texture);
	plr->x = &plr->p_img->instances->x;
	plr->y = &plr->p_img->instances->y;
}

void	create_world(t_world *wld, t_map *map, t_player *plr)
{
	int				ix;
	int				iy;
	mlx_texture_t	*w_texture;

	w_texture = mlx_load_png
		("/Users/rmaes/Projects/so_long/textures/brick.png");
	wld->w_img = mlx_new_image(wld->mlx, map->y * 20, map->x * 20);
	ix = 0;
	wld->plr = plr;
	while (map->map[ix])
	{
		iy = 0;
		while (map->map[ix][iy])
		{
			if (map->map[ix][iy] == '1')
				mlx_draw_texture(wld->w_img, w_texture, iy * 20, ix * 20);
			iy++;
		}
		ix++;
	}
	write(1, "hey", 3);
}

void	images(t_map *map)
{
	t_player	plr;
	t_world		wld;

	wld.mlx = mlx_init(map->y * 20, map->x * 20, "so_long", false);
	if (!wld.mlx)
		error(ERR_MLX_INIT);
	write(1, "hey", 3);
	create_world(&wld, map, &plr);
	write(1, "hey", 3);
	mlx_image_to_window(wld.mlx, wld.w_img, 0, 0);
	create_player(&plr, &wld);
	mlx_image_to_window(wld.mlx, plr.p_img,
		map->player[1] * 20, map->player[0] * 20);
	mlx_loop_hook(wld.mlx, &test, &wld);
	mlx_loop(wld.mlx);
	mlx_terminate(wld.mlx);
}
