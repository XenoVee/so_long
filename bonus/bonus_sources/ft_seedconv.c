/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_seedconv.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/20 19:15:57 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/02 20:46:27 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"

t_seed	ft_seedconv(char	*str)
{
	unsigned long	ret;
	int				i;

	ret = 0;
	i = 0;
	if (ft_is_atoi(str))
		return (ft_atoul(str));
	while (str[i])
	{
		ret += str[i];
		i++;
	}
	return (ret);
}
