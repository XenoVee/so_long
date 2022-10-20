/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 15:15:44 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/20 18:06:24 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libftprintf/libft.h"
# include "err_msg.h"
# include "errno.h"

typedef struct s_map
{
	unsigned int	x;
	unsigned int	y;
	char			**map;
}				t_map;

void	error(char *errmsg);
int		check_ext(char *file);
void	open_file(char *filepath, t_map *map);
void	parsing(t_map *map);
void	check_enclosed(t_map *map);
void	char_valid(char c, char *v_chars);

#endif
