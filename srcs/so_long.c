/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 10:46:48 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/16 13:38:44 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_init(t_img *game)
{
	game->move_count = 0;
	game->col_count = 0;
	game->win_width = game->max_x * 64;
	game->win_height = game->max_y * 64;
	game->pos_x = 0;
	game->pos_y = 0;
	game->mlx_ptr = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->win_width, \
	game->win_height, "so_long v1.0");
	ft_load_images(game);
}

int	main(int argc, char **argv)
{
	t_img	game;

	if (argc != 2)
		return (ft_printf("\033[0;31m%s\e[0m", NOMAPERROR));
	if (!ft_strstr(argv[1], ".ber"))
		return (ft_printf("\033[0;31m%s\e[0m", WRONGFORMAT));
	if (ft_map_read(argv[1], &game) == 1)
	{
		ft_printf("\033[0;31m%s\e[0m", MAPERROR);
		return (0);
	}
	ft_init(&game);
	ft_map_build(&game);
	mlx_hook(game.mlx_win, 2, 0, key_press, &game);
	mlx_hook(game.mlx_win, 17, 0, close_window, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
