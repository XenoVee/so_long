/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   things.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/14 17:12:13 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/02 21:17:00 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"

void	ft_collectibles(t_params *prms, unsigned int ncoll)
{
	while (ncoll)
	{
		put_thing(prms, 'C');
		ncoll--;
	}
}
