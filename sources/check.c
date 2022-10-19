/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 15:11:31 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/18 17:18:24 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_ext(char *file)
{
	int	i;

	i = ft_strlen(file) - 4;
	return (ft_strncmp(&file[i], ".ber", 4));
}
