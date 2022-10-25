/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   err.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 14:04:50 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/25 21:22:53 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_MSG_H
# define ERR_MSG_H

#include "so_long.h"

typedef struct s_err
{
	int		players;
	int		exits;
	int		collect;
	int		closed;
	t_list	*list;
}				t_err;

# define ERR_FILE			"Provide only a single mapfile: ./so_long <mapfile>"
# define ERR_FILE_EXT		"map files must have the .ber file extention"
# define ERR_FD				"Couldn't open file"
# define ERR_MAP_RECT		"Map is not a rectangle"
# define ERR_ENCLOSED		"Map is not properly enclosed in walls"
# define ERR_INVALID_CHAR	"Map contains invalid characters:"
# define ERR_PLAYER			"Map must have exactly one player"
# define ERR_EXIT			"Map must have exactly one exit"
# define ERR_NO_COLLECT		"Map has no collectibles"
# define ERR_SOLVE			"Map is not solvable"
#endif