/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collectibles.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/03 21:00:30 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/07 16:45:40 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_collectibles(t_game *game)
{
	t_collect	*collect;
	int			i;

	i = 0;
	collect = game->collect;
}
// {
// 	t_collect	*collect;
// 	int			i;

// 	i = 0;
// 	collect = game->collect;
// 	collect->c_text = mlx_load_png
// 		("/Users/rmaes/Projects/so_long/textures/orb.png");
// 	collect->c_img = mlx_texture_to_image(game->mlx, collect->c_text);
// 	while (i < game->map->ncollect)
// 	{
// 		mlx_image_to_window(game->mlx, collect->c_img,
// 			game->map->collect[i][0], game->map->collect[i][1]);
// 		i++;
// 	}
// }
