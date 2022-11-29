/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/29 14:31:06 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/29 14:31:43 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_exit(t_game *game)
{
	game->exit.e_text = mlx_load_png
		("textures/exit.png");
	game->exit.e_img = mlx_texture_to_image(game->mlx, game->exit.e_text);
	mlx_image_to_window(game->mlx, game->exit.e_img,
		game->map->exit[1] * game->hi, game->map->exit[0] * game->wi);
	game->exit.active = false;
}
