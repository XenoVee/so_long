/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/17 15:15:44 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/18 17:59:30 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libftprintf/libft.h"
# include "err_msg.h"
# include "errno.h"

void	error(char *errmsg);
int		check_ext(char *file);
int		open_file(char *filepath);

#endif
