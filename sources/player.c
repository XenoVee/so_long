/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 18:27:31 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/16 21:32:24 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>

void	load_player_textures(t_player *plr)
{
	int		dir;
	int		frame;
	char	*file;

	dir = 0;
	frame = 0;
	file = ft_calloc(25, sizeof(char));
	file[24] = '\0';
	ft_memcpy(file, "textures/char/char", 18);
	ft_memcpy(&file[20], ".png", 4);
	while (dir < 8)
	{
		frame = 0;
		while (frame < 4)
		{
			ft_memcpy(&file[18], ft_itoa(dir), 1);
			ft_memcpy(&file[19], ft_itoa(frame), 1);
			plr->p_text[dir][frame] = mlx_load_png(file);
			frame++;
		}
		dir++;
	}
	free(file);
}

void	create_player(t_game *game)
{
	load_player_textures(&game->plr);
	game->plr.p_img = mlx_texture_to_image
		(game->mlx, game->plr.p_text[down][stand]);
	mlx_image_to_window(game->mlx, game->plr.p_img,
		game->map->player[1] * game->wi, game->map->player[0] * game->hi);
	game->plr.x = &game->plr.p_img->instances->x;
	game->plr.y = &game->plr.p_img->instances->y;
	game->plr.speed_x = 0;
	game->plr.speed_y = 0;
}

void	player_anim(t_player *plr, mlx_t *mlx, int dir_x, int dir_y)
{
	static int	frame = 0;
	int			fpause;

	fpause = 10;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT_SHIFT))
		fpause = 6;
	if (dir_x == 1 && dir_y == 0)
		mlx_draw_texture(plr->p_img, plr->p_text[right][frame / fpause], 0, 0);
	if (dir_x == -1 && dir_y == 0)
		mlx_draw_texture(plr->p_img, plr->p_text[left][frame / fpause], 0, 0);
	if (dir_x == 0 && dir_y == -1)
		mlx_draw_texture(plr->p_img, plr->p_text[up][frame / fpause], 0, 0);
	if (dir_x == 0 && dir_y == 1)
		mlx_draw_texture(plr->p_img, plr->p_text[down][frame / fpause], 0, 0);
	if (dir_x == 1 && dir_y == -1)
		mlx_draw_texture(plr->p_img, plr->p_text[up_r][frame / fpause], 0, 0);
	if (dir_x == 1 && dir_y == 1)
		mlx_draw_texture(plr->p_img, plr->p_text[down_r][frame / fpause], 0, 0);
	if (dir_x == -1 && dir_y == -1)
		mlx_draw_texture(plr->p_img, plr->p_text[up_l][frame / fpause], 0, 0);
	if (dir_x == -1 && dir_y == 1)
		mlx_draw_texture(plr->p_img, plr->p_text[down_l][frame / fpause], 0, 0);
	frame++;
	if (frame >= fpause * 4)
		frame = 0;
}
