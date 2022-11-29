/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 18:04:34 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/28 18:18:31 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../so_long.h"
# include "t_player.h"
# include "t_world.h"

enum e_xy
{
	x = 0,
	y,
};

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

typedef struct s_exit
{
	mlx_image_t		*e_img;
	mlx_texture_t	*e_text;
	bool			active;
}				t_exit;

typedef struct s_collect
{
	mlx_image_t		*c_img;
	mlx_texture_t	*c_text;
	int				**inst;
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
	t_collect	coll;
}				t_game;

#endif