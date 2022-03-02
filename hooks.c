/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 16:56:21 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/02 16:59:20 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	{
		if (keys->map[keys->player_i - 1][keys->player_j] == '1')
			return (0);
		if (keys->map[keys->player_i - 1][keys->player_j] == 'C')
		{
			keys->map[keys->player_i - 1][keys->player_j] = '0';
			keys->col_count--;
			keys->move_count++;
		}
		if (keys->map[keys->player_i - 1][keys->player_j] == 'E')
		{
			if (keys->col_count == 0)
			{
				keys->move_count++;
				ft_printf("\033[0;32m%s\e[0m\n", GAMEWIN);
				ft_printf("\033[0;32m%s%d\e[0m\n", TOTALMOVES, keys->move_count);
				return (close_window(keys));
			}
			else
				return (ft_printf("\033[0;31m%s\e[0m\n", GAMENOTOVER));
		}
		ft_key_basic(keys, keycode);
		ft_key_img_push(keys);
	}
	if (keycode == KEY_S)
	{
		if (keys->map[keys->player_i + 1][keys->player_j] == '1')
			return (0);
		if (keys->map[keys->player_i + 1][keys->player_j] == 'C')
		{
			keys->map[keys->player_i + 1][keys->player_j] = '0';
			keys->col_count--;
		}
		if (keys->map[keys->player_i + 1][keys->player_j] == 'E')
		{
			if (keys->col_count == 0)
			{
				keys->move_count++;
				ft_printf("\033[0;32m%s\e[0m\n", GAMEWIN);
				ft_printf("\033[0;32m%s%d\e[0m\n", TOTALMOVES, keys->move_count);
				return (close_window(keys));
			}
			else
				return (ft_printf("\033[0;31m%s\e[0m\n", GAMENOTOVER));
		}
		ft_key_basic(keys, keycode);
		ft_key_img_push(keys);
	}
	if (keycode == KEY_A)
	{
		if (keys->map[keys->player_i][keys->player_j - 1] == '1')
			return (0);
		if (keys->map[keys->player_i][keys->player_j - 1] == 'C')
		{
			keys->map[keys->player_i][keys->player_j - 1] = '0';
			keys->col_count--;
		}
		if (keys->map[keys->player_i][keys->player_j - 1] == 'E')
		{
			if (keys->col_count == 0)
			{
				keys->move_count++;
				ft_printf("\033[0;32m%s\e[0m\n", GAMEWIN);
				ft_printf("\033[0;32m%s%d\e[0m\n", TOTALMOVES, keys->move_count);
				return (close_window(keys));
			}
			else
				return (ft_printf("\033[0;31m%s\e[0m\n", GAMENOTOVER));
		}
		ft_key_basic(keys, keycode);
		ft_key_img_push(keys);
	}
	if (keycode == KEY_D)
	{
		if (keys->map[keys->player_i][keys->player_j + 1] == '1')
			return (0);
		if (keys->map[keys->player_i][keys->player_j + 1] == 'C')
		{
			keys->map[keys->player_i][keys->player_j + 1] = '0';
			keys->col_count--;
		}
		if (keys->map[keys->player_i][keys->player_j + 1] == 'E')
		{
			if (keys->col_count == 0)
			{
				keys->move_count++;
				ft_printf("\033[0;32m%s\e[0m\n", GAMEWIN);
				ft_printf("\033[0;32m%s%d\e[0m\n", TOTALMOVES, keys->move_count);
				return (close_window(keys));
			}
			else
				return (ft_printf("\033[0;31m%s\e[0m\n", GAMENOTOVER));
		}
		ft_key_basic(keys, keycode);
		ft_key_img_push(keys);
	}
	return (0);
}
