/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   t_player.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 14:17:54 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/14 18:24:14 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PLAYER_H
# define T_PLAYER_H

# include "../so_long.h"

enum e_spritesets
{
	down = 0,
	down_left,
	left,
	up_left,
	up,
	up_right,
	right,
	down_right,
};

enum e_sprites
{
	move_1 = 0,
	idle,
	move_2,
};

typedef struct s_player
{
	mlx_image_t		*p_img;
	mlx_texture_t	*p_text;
	int				*x;
	int				*y;
	int				speed_x;
	int				speed_y;
	int				dir[2];
}				t_player;

#endif