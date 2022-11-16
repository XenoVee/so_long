/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   err.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 14:04:50 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/16 20:16:31 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_MSG_H
# define ERR_MSG_H

#include "../so_long.h"

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
# define ERR_SOLVE			"Map can't be solved:"
# define ERR_SOLVE_EXIT		"Exit can't be reached"
# define ERR_SOLVE_COLLECT	"Collectible can't be reached at: "
# define ERR_MLX_INIT		"MLX initialization failed"
# define ERR_SIDES			"Map sides must be at least 4 spaces long"
# define ERR_CREATE_MAP		"Failed to create map"
# define ERR_READ_RAND		"Failed to read /dev/random"
# define ERR_MALLOC			"Malloc call returned NULL"
#endif