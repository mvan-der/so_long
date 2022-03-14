/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_build.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 10:53:04 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/14 15:11:41 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_load_images(t_img *game)
{
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "./img/wall.xpm", \
	&game->img_width, &game->img_height);
	game->ground = mlx_xpm_file_to_image(game->mlx_ptr, "./img/ground.xpm", \
	&game->img_width, &game->img_height);
	game->coll = mlx_xpm_file_to_image(game->mlx_ptr, "./img/collectible.xpm", \
	&game->img_width, &game->img_height);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr, "./img/exit.xpm", \
	&game->img_width, &game->img_height);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, "./img/player.xpm", \
	&game->img_width, &game->img_height);
	if (!game->wall || !game->ground || !game->coll || !game->exit || \
	!game->player)
	{
		ft_printf("\033[0;31m%s\e[0m", IMGERROR);
		exit(0);
	}
}

void	ft_map_build(t_img *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map && i < game->max_y)
	{
		j = 0;
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
		game->pos_y += 64;
		game->pos_x = 0;
		i++;
	}
}
