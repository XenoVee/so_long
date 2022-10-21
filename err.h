/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   err_msg.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 14:04:50 by rmaes         #+#    #+#                 */
/*   Updated: 2022/10/20 21:27:22 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_MSG_H
# define ERR_MSG_H

# define ERR_FILE			"Provide only a single mapfile: ./so_long <mapfile>"
# define ERR_FILE_EXT		"map files must have the .ber file extention"
# define ERR_FD				"Couldn't open file"
# define ERR_MAP_RECT		"Map is not a rectangle"
# define ERR_ENCLOSED		"Map is not properly enclosed in walls"
# define ERR_INVALID_CHAR	"Map contains invalid characters:"
# define ERR_MORE_PLAYERS	"More than one player in map"
# define ERR_MORE_EXITS		"More than one exit in map"
# define ERR_NO_PLAYER		"Map has no player"
# define ERR_NO_EXIT		"Map has no exit"
# define ERR_NO_COLLECT		"Map has no collectibles"

#endif