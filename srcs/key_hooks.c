/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 16:56:21 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/03 12:13:45 by mvan-der      ########   odam.nl         */
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
		ft_key_w(keys, keycode);
	if (keycode == KEY_S)
		ft_key_s(keys, keycode);
	if (keycode == KEY_A)
		ft_key_a(keys, keycode);
	if (keycode == KEY_D)
		ft_key_d(keys, keycode);
	return (0);
}
