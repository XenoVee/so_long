/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_wall.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/09 17:05:18 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/09 18:23:33 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_sides(t_game *game, int x, int y, int side[5])
{
	ft_null_array(side, 5);
	if (game->map->map[x][y] != '1')
		side[total] = -1;
	else
	{
		if (x > 0)
			if (game->map->map[x - 1][y] == '1')
				side[north] = 1;
		if (y < game->map->y - 1)
			if (game->map->map[x][y + 1] == '1')
				side[east] = 1;
		if (x < game->map->x - 1)
			if (game->map->map[x + 1][y] == '1')
				side[south] = 1;
		if (y > 0)
			if (game->map->map[x][y - 1] == '1')
				side[west] = 1;
		side[total] = side[north] + side[east] + side[south] + side[west];
	}
}

void	put_corner_straight(t_game *game, int x, int y, int side[5])
{
	if (side[north] && side[south])
		mlx_draw_texture(game->wld.w_img, game->wld.w_text[vertical],
			y * game->wi, x * game->hi);
	if (side[west] && side[east])
		mlx_draw_texture(game->wld.w_img, game->wld.w_text[horizontal],
			y * game->wi, x * game->hi);
	if (side[north] && side[west])
		mlx_draw_texture(game->wld.w_img, game->wld.w_text[corner_4],
			y * game->wi, x * game->hi);
	if (side[north] && side[east])
		mlx_draw_texture(game->wld.w_img, game->wld.w_text[corner_2],
			y * game->wi, x * game->hi);
	if (side[south] && side[west])
		mlx_draw_texture(game->wld.w_img, game->wld.w_text[corner_1],
			y * game->wi, x * game->hi);
	if (side[south] && side[east])
		mlx_draw_texture(game->wld.w_img, game->wld.w_text[corner_3],
			y * game->wi, x * game->hi);
}

void	put_end(t_game *game, int x, int y, int side[5])
{
	if (side[north])
		mlx_draw_texture(game->wld.w_img, game->wld.w_text[end_down],
			y * game->wi, x * game->hi);
	if (side[east])
		mlx_draw_texture(game->wld.w_img, game->wld.w_text[end_left],
			y * game->wi, x * game->hi);
	if (side[south])
		mlx_draw_texture(game->wld.w_img, game->wld.w_text[end_up],
			y * game->wi, x * game->hi);
	if (side[west])
		mlx_draw_texture(game->wld.w_img, game->wld.w_text[end_right],
			y * game->wi, x * game->hi);
}

void	put_t(t_game *game, int x, int y, int side[5])
{
	if (side[north] && side[east] && side[south])
		mlx_draw_texture(game->wld.w_img, game->wld.w_text[t_right],
			y * game->wi, x * game->hi);
	if (side[east] && side[south] && side[west])
		mlx_draw_texture(game->wld.w_img, game->wld.w_text[t_down],
			y * game->wi, x * game->hi);
	if (side[north] && side[south] && side[west])
		mlx_draw_texture(game->wld.w_img, game->wld.w_text[t_left],
			y * game->wi, x * game->hi);
	if (side[north] && side[east] && side[west])
		mlx_draw_texture(game->wld.w_img, game->wld.w_text[t_up],
			y * game->wi, x * game->hi);
}

void	put_wall(t_game *game, int x, int y)
{
	int	side[5];

	check_sides(game, x, y, side);
	if (side[total] == -1)
		return ;
	if (side[total] == 4)
		mlx_draw_texture(game->wld.w_img, game->wld.w_text[center],
			y * game->wi, x * game->hi);
	else if (side[total] == 3)
		put_t(game, x, y, side);
	else if (side[total] == 2)
		put_corner_straight(game, x, y, side);
	else if (side[total] == 1)
		put_end(game, x, y, side);
	else
		mlx_draw_texture(game->wld.w_img, game->wld.w_text[pillar],
			y * game->wi, x * game->hi);
}
