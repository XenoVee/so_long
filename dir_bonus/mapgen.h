/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapgen.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 19:57:57 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/02 22:31:02 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPGEN_H
# define MAPGEN_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libftprintf/libft.h"
# include "../so_long.h"
// # include <stddef.h>

typedef struct s_params
{
	unsigned long	seed;
	unsigned int	x;
	unsigned int	y;
	unsigned int	player[2];
	unsigned int	size;
	char			**map;
}				t_params;

typedef unsigned long	t_seed;

char	*ft_map_malloc(unsigned long count, unsigned long size);
char	**ft_create_map(t_params *prms);
void	*free_map(t_params *prms, int malloced);
void	ft_print_map(t_params *prms);
void	ft_fill_map(t_params *prms);
t_seed	ft_seedconv(char *str);
void	ft_parse_args(int argc, char **argv, t_params *prms);
void	ft_setup_params(int argc, char **argv, t_params *prms);
void	ft_rooms(t_params *prms, unsigned int nrooms);
void	ft_generate_room(unsigned int room[2][2], t_params *prms);
void	ft_draw_room(unsigned int room[2][2], t_params *prms);
void	ft_draw_door(t_params *prms, unsigned int room[2][2]);
int		check_space(unsigned int room[2][2], t_params *prms);
void	ft_rocks(t_params *prms, unsigned int nrocks);
void	draw_rock(t_params *prms, unsigned int rock[2]);
void	ft_finalize(t_params *prms, char c, char f);
void	ft_collectibles(t_params *prms, unsigned int ncoll);
void	ft_player_exit(t_params *prms);
void	put_thing(t_params *prms, char c);

#endif
