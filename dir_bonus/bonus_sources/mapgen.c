/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapgen.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/19 18:04:32 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/02 22:33:35 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"

void	mapgen(int argc, char **argv, t_map *map)
{
	t_params	prms;

	ft_setup_params(argc, argv, &prms);
	prms.map = ft_create_map(&prms);
	if (prms.map == NULL)
		error(ERR_CREATE_MAP);
	ft_fill_map(&prms);
	ft_print_map(&prms);
	map->map = prms.map;
	map->x = prms.x;
	map->y = prms.y;
	map->player[0] = prms.player[0];
	map->player[1] = prms.player[1];
}
