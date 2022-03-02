/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_build.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 10:53:04 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/02 11:42:09 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init(t_img *game)
{
	game->move_count = 0;
	game->col_count = 0;
	game->win_width = game->max_x * 50;
	game->win_height = game->max_y * 50;
	game->pos_x = 0;
	game->pos_y = 0;
	game->mlx_ptr = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->win_width, \
	game->win_height, "so_long v0.4");
	open_xpm(game);
}

static void	ft_reset(t_img *game)
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
		ft_reset(game);
		j = 0;
		i++;
	}
}
