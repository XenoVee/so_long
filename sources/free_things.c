/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_things.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/30 16:12:06 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/30 17:10:51 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>

void	free_instances(t_game *game)
{
	int	i;

	i = 0;
	while (game->coll.inst[i])
	{
		free(game->coll.inst[i]);
		i++;
	}
	free (game->coll.inst);
}

void	free_textures(t_game *game)
{
	int		i;

	i = 0;
	mlx_delete_texture(game->exit.e_text);
	mlx_delete_texture(game->coll.c_text);
	while (i < 16)
	{
		mlx_delete_texture(game->wld.w_text[i]);
		if (i < 5)
		{
			mlx_delete_texture(game->wld.g_text[i]);
			mlx_delete_texture(game->exit.op_text[i]);
		}
		if (i < 8)
		{
			mlx_delete_texture(game->plr.p_text[i][0]);
			mlx_delete_texture(game->plr.p_text[i][1]);
			mlx_delete_texture(game->plr.p_text[i][2]);
			mlx_delete_texture(game->plr.p_text[i][3]);
		}
		i++;
	}
}

void	free_things(t_game *game)
{
	free_textures(game);
	free_instances(game);
}
