/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   t_player.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 14:17:54 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/15 19:47:38 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PLAYER_H
# define T_PLAYER_H

# include "../so_long.h"

enum e_spritesets
{
	down = 0,
	down_l,
	left,
	up_l,
	up,
	up_r,
	right,
	down_r,
};

enum e_sprites
{
	stand = 0,
	move_1,
	stand_2,
	move_2,
};

typedef struct s_player
{
	mlx_image_t		*p_img;
	mlx_texture_t	*p_text[8][4];
	int				*x;
	int				*y;
	int				speed_x;
	int				speed_y;
	int				dir[2];
}				t_player;

#endif