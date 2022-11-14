/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   t_player.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 14:17:54 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/14 14:23:24 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PLAYER_H
# define T_PLAYER_H

# include "../so_long.h"

enum e_spritesets
{
	up = 0,
	up_right,
	right,
	down_right,
	down,
	down_left,
	left,
	up_left,
};

enum e_sprites
{
	idle = 0,
	move_1,
	move_2,
};

typedef struct s_player
{
	mlx_image_t		*p_img;
	mlx_texture_t	*p_text;
	int				*x;
	int				*y;
}				t_player;

#endif