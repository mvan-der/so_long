/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   open_xpm.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 10:54:09 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/02 12:18:04 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_xpm(t_img *game)
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
