/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_setup_params.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmaes <rmaes@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/21 16:03:51 by rmaes         #+#    #+#                 */
/*   Updated: 2022/11/03 15:47:32 by rmaes         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../mapgen.h"
#include <time.h>

int	sizecalc(int x, int y)
{
	return (ft_min((x + y) / 2, ft_min(x, y) + (ft_min(x, y) / 2)));
}

void	ft_parse_args(int argc, char **argv, t_params *prms)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strncmp(argv[i], "-s", 2))
			prms->seed = ft_seedconv(argv[i + 1]);
		if (!ft_strncmp(argv[i], "-x", 2))
			prms->y = ft_atoi(argv[i + 1]);
		if (!ft_strncmp(argv[i], "-y", 2))
			prms->x = ft_atoi(argv[i + 1]);
		i += 2;
	}
}

void	null_params(t_params *prms)
{
	prms->seed = 0;
	prms->x = 0;
	prms->y = 0;
	prms->size = 0;
	prms->map = NULL;
	prms->player[0] = 0;
	prms->player[1] = 0;
}

void	ft_setup_params(int argc, char **argv, t_params *prms)
{
	null_params(prms);
	if (argc == 2)
		prms->seed = ft_seedconv(argv[1]);
	if (argc > 2)
		ft_parse_args(argc, argv, prms);
	if (prms->seed <= 0)
		prms->seed = time(NULL) * getpid();
	srand(prms->seed);
	if (prms->x == 0)
		prms->x = rand() % 20 + 10;
	if (prms->y == 0)
		prms->y = rand() % 20 + 10;
	if (prms->x < 4 || prms->y < 4)
		error(ERR_SIDES);
	prms->size = sizecalc(prms->x, prms->y);
	return ;
}
