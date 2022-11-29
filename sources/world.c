/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   world.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 18:39:23 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/18 20:19:07 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	put_grass(t_game *game, int x, int y, char *buf)
{
	int		r;
	t_world	*w;

	w = &game->wld;
	r = (unsigned char)buf[0] % 20;
	shift_buf(buf);
	if (r >= 4)
		mlx_draw_texture(w->w_img, w->g_text[0], y * game->wi, x * game->hi);
	if (r == 0)
		mlx_draw_texture(w->w_img, w->g_text[1], y * game->wi, x * game->hi);
	if (r == 1)
		mlx_draw_texture(w->w_img, w->g_text[2], y * game->wi, x * game->hi);
	if (r == 2)
		mlx_draw_texture(w->w_img, w->g_text[3], y * game->wi, x * game->hi);
	if (r == 3)
		mlx_draw_texture(w->w_img, w->g_text[4], y * game->wi, x * game->hi);
}

void	create_world_image(t_game *game)
{
	int		ix;
	int		iy;
	int		fd;
	char	buf[20];

	fd = open("/dev/urandom", O_RDONLY);
	buf[0] = '\0';
	ix = 0;
	while (game->map->map[ix])
	{
		iy = 0;
		while (game->map->map[ix][iy])
		{
			if (buf[0] == '\0')
				read_buf(fd, buf, 19);
			if (game->map->map[ix][iy] == '1')
				put_wall(game, ix, iy);
			if (game->map->map[ix][iy] != '1')
				put_grass(game, ix, iy, buf);
			iy++;
		}
		ix++;
	}
	close(fd);
}

void	load_textures(t_game *game)
{
	game->wld.g_text[0] = mlx_load_png("textures/grass/grass0.png");
	game->wld.g_text[1] = mlx_load_png("textures/grass/grass1.png");
	game->wld.g_text[2] = mlx_load_png("textures/grass/grass2.png");
	game->wld.g_text[3] = mlx_load_png("textures/grass/grass3.png");
	game->wld.g_text[4] = mlx_load_png("textures/grass/grass4.png");
	game->wld.w_text[center] = mlx_load_png("textures/walls/center.png");
	game->wld.w_text[pillar] = mlx_load_png("textures/walls/pillar.png");
	game->wld.w_text[corner_1] = mlx_load_png("textures/walls/corner_1.png");
	game->wld.w_text[corner_2] = mlx_load_png("textures/walls/corner_2.png");
	game->wld.w_text[corner_3] = mlx_load_png("textures/walls/corner_3.png");
	game->wld.w_text[corner_4] = mlx_load_png("textures/walls/corner_4.png");
	game->wld.w_text[end_up] = mlx_load_png("textures/walls/end_up.png");
	game->wld.w_text[end_left] = mlx_load_png("textures/walls/end_left.png");
	game->wld.w_text[end_down] = mlx_load_png("textures/walls/end_down.png");
	game->wld.w_text[end_right] = mlx_load_png("textures/walls/end_right.png");
	game->wld.w_text[horizontal] = mlx_load_png("textures/walls/flat.png");
	game->wld.w_text[vertical] = mlx_load_png("textures/walls/up.png");
	game->wld.w_text[t_up] = mlx_load_png("textures/walls/t_up.png");
	game->wld.w_text[t_left] = mlx_load_png("textures/walls/t_left.png");
	game->wld.w_text[t_down] = mlx_load_png("textures/walls/t_down.png");
	game->wld.w_text[t_right] = mlx_load_png("textures/walls/t_right.png");
}

void	create_world(t_game *game)
{
	t_world	*wld;
	t_map	*map;

	wld = &game->wld;
	map = game->map;
	load_textures(game);
	game->wi = wld->w_text[pillar]->width;
	game->hi = wld->w_text[pillar]->height;
	game->mlx = mlx_init(map->y * game->wi, map->x * game->hi,
			"so_long", false);
	if (!game->mlx)
		error(ERR_MLX_INIT);
	wld->w_img = mlx_new_image(game->mlx, game->mlx->width, game->mlx->height);
	create_world_image(game);
	mlx_image_to_window(game->mlx, wld->w_img, 0, 0);
}
