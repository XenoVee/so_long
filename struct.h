/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 18:04:34 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/07 21:39:27 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "so_long.h"

typedef struct s_player
{
	mlx_image_t		*p_img;
	int				*x;
	int				*y;
	mlx_texture_t	*p_text;
}				t_player;

typedef struct s_map
{
	unsigned int	x;
	unsigned int	y;
	char			**map;
	int				player[2];
	int				exit[2];
	int				ncollect;
	int				**collect;
}				t_map;

enum e_wall_sides
{
	top = 0,
	right,
	bottom,
	left,
};

typedef struct s_world
{
	mlx_image_t		*w_img;
	mlx_texture_t	*w_text[7];
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
	t_world		*wld;
	t_player	*plr;
	t_map		*map;
	t_exit		*exit;
	t_collect	*collect;
}				t_game;

#endif