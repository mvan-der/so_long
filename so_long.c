/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 10:46:48 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/01 15:48:24 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(t_img *release)
{
	mlx_destroy_window(release->mlx_ptr, release->mlx_win);
	exit (0);
}

int key_press(int keycode, t_img *keys)
{
	if (keycode == 53)
		close_window(keys);
	if (keycode == 13) //up
	{
		keys->pos_y = keys->pos_y - 50;
		mlx_put_image_to_window(keys->mlx_ptr, keys->mlx_win, keys->player, keys->pos_x, keys->pos_y);
	}
	if (keycode == 1) //down
	{
		keys->pos_y = keys->pos_y + 50;
		mlx_put_image_to_window(keys->mlx_ptr, keys->mlx_win, keys->player, keys->pos_x, keys->pos_y);
	}
	if (keycode == 0) // left
	{
		keys->pos_x = keys->pos_x - 50;
		mlx_put_image_to_window(keys->mlx_ptr, keys->mlx_win, keys->player, keys->pos_x, keys->pos_y);
	}
	if (keycode == 2) //right
	{
		keys->pos_x = keys->pos_x + 50;
		mlx_put_image_to_window(keys->mlx_ptr, keys->mlx_win, keys->player, keys->pos_x, keys->pos_y);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_img	game;

	if (argc != 2)
		return (ft_printf("\033[0;31mNo map provided or too many maps provided\e[0m\n"));
	// map input check
	if (map_read(argv[1], &game) == 1)
	{
		ft_printf("\033[0;31m%s\e[0m", MAPERROR);
		ft_free_map(&game);
		return (0);
	}
	map_build(&game);
	mlx_hook(game.mlx_win, 2, 0, key_press, &game);
	mlx_hook(game.mlx_win, 17, 0, close_window, &game);
	ft_printf("\033[0;32mHuzzah!\e[0m\n");
	mlx_loop(game.mlx_ptr);
	return (0);
}
