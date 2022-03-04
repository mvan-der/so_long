/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hooks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 16:56:21 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/04 10:49:37 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(t_img *release)
{
	mlx_destroy_window(release->mlx_ptr, release->mlx_win);
	exit (0);
}

int	key_press(int keycode, t_img *keys)
{
	if (keycode == KEY_ESC)
		close_window(keys);
	if (keycode == KEY_W)
		ft_key(keys, keycode, 0, -1);
	if (keycode == KEY_S)
		ft_key(keys, keycode, 0, 1);
	if (keycode == KEY_A)
		ft_key(keys, keycode, -1, 0);
	if (keycode == KEY_D)
		ft_key(keys, keycode, 1, 0);
	return (0);
}
