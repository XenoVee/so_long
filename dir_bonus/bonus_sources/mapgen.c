/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapgen.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/19 18:04:32 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/02 21:53:14 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"

char	**mapgen(int argc, char **argv)
{
	t_params	prms;

	ft_setup_params(argc, argv, &prms);
	prms.map = ft_create_map(&prms);
	if (prms.map == NULL)
		return (0);
	ft_fill_map(&prms);
	ft_print_map(&prms);
	return (prms.map);
}
