/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 18:04:34 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/14 14:21:23 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../so_long.h"

typedef struct s_map
{
	int		x;
	int		y;
	char	**map;
	int		player[2];
	int		exit[2];
	int		ncollect;
	int		**collect;
}				t_map;

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

typedef struct s_exit
{
	mlx_image_t		*e_img;
	mlx_texture_t	*e_text;
}				t_exit;

typedef struct s_collect
{
	mlx_image_t		*c_img;
	mlx_texture_t	*c_text;
}				t_collect;

typedef struct s_game
{
	int			wi;
	int			hi;
	mlx_t		*mlx;
	t_world		wld;
	t_player	plr;
	t_map		*map;
	t_exit		exit;
	t_collect	collect;
}				t_game;

#endif