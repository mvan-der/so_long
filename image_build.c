/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_build.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 11:08:29 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/02 11:22:11 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_wall_image(t_img *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->wall, \
	game->pos_x, game->pos_y);
	game->pos_x += 50;
}

void	ft_ground_image(t_img *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->ground, \
	game->pos_x, game->pos_y);
	game->pos_x += 50;
}

void	ft_coll_image(t_img *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->coll, \
	game->pos_x, game->pos_y);
	game->pos_x += 50;
	game->col_count++;
}

void	ft_exit_image(t_img *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->exit, \
	game->pos_x, game->pos_y);
	game->pos_x += 50;
}

void	ft_player_image(t_img *game, int i, int j)
{
	game->player_i = i;
	game->player_j = j;
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->player, \
	game->pos_x, game->pos_y);
	game->player_pos_x = game->pos_x;
	game->player_pos_y = game->pos_y;
	game->pos_x += 50;
}
