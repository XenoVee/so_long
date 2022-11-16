/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   t_world.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 19:26:14 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/16 19:27:59 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_WORLD_H
# define T_WORLD_H
# include "../so_long.h"

enum e_sides
{
	north = 0,
	east,
	south,
	west,
	total,
};

enum e_wall_sprites
{
	center = 0,
	pillar,
	corner_1,
	corner_2,
	corner_3,
	corner_4,
	end_up,
	end_left,
	end_down,
	end_right,
	horizontal,
	vertical,
	t_up,
	t_left,
	t_down,
	t_right,
};

typedef struct s_world
{
	mlx_image_t		*w_img;
	mlx_texture_t	*w_text[16];
	mlx_texture_t	*g_text[5];
}				t_world;

#endif