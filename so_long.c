/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 10:46:48 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/02 12:41:11 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_img	game;

	if (argc != 2)
		return (ft_printf("\033[0;31m%s\e[0m", NOMAPERROR));
	if (map_read(argv[1], &game) == 1)
	{
		ft_printf("\033[0;31m%s\e[0m", MAPERROR);
		ft_free_map(&game);
		return (0);
	}
	ft_init(&game);
	ft_map_build(&game);
	mlx_hook(game.mlx_win, 2, 0, key_press, &game);
	mlx_hook(game.mlx_win, 17, 0, close_window, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
