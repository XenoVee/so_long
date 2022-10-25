/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 15:11:31 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/21 18:28:11 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_ext(char *file)
{
	int	i;

	i = ft_strlen(file) - 4;
	return (ft_strncmp(&file[i], ".ber", 4));
}

int	char_valid(char c, char *v_chars)
{
	int	i;
	int	valid;

	i = 0;
	valid = 0;
	while (v_chars[i] && valid != 1)
	{
		if (c == v_chars[i])
			valid = 1;
		i++;
	}
	if (valid != 1)
		return (0);
	return (1);
}
