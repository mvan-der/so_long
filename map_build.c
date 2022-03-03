/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_build.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 10:53:04 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/03 12:01:16 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_update(t_img *game)
{
	game->pos_y += 50;
	game->pos_x = 0;
}

void	ft_map_build(t_img *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map && i < game->max_y)
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				ft_wall_image(game);
			if (game->map[i][j] == '0')
				ft_ground_image(game);
			if (game->map[i][j] == 'C')
				ft_coll_image(game);
			if (game->map[i][j] == 'E')
				ft_exit_image(game);
			if (game->map[i][j] == 'P')
				ft_player_image(game, i, j);
			j++;
		}
		ft_update(game);
		j = 0;
		i++;
	}
}
