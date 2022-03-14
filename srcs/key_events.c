/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_events.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 08:59:23 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/14 14:45:13 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_key(t_img *keys, int keycode, int dx, int dy)
{
	if (keys->map[keys->player_i + dy][keys->player_j + dx] == '1')
		return (0);
	if (keys->map[keys->player_i + dy][keys->player_j + dx] == 'C')
	{
		keys->col_count--;
		keys->map[keys->player_i + dy][keys->player_j + dx] = '0';
	}
	if (keys->map[keys->player_i + dy][keys->player_j + dx] == 'E')
	{
		ft_key_exit(keys);
		return (0);
	}
	ft_key_basic(keys, keycode);
	ft_key_img_push(keys);
	return (0);
}

void	ft_key_exit(t_img *keys)
{
	if (keys->col_count == 0)
	{
		keys->move_count++;
		ft_printf("\033[0;32m%s\e[0m\n", GAMEWIN);
		ft_printf("\033[0;32m%s%d\e[0m\n", TOTALMOVES, keys->move_count);
		close_window(keys);
	}
	else
		ft_printf("\033[0;31m%s%d\e[0m\n", GAMENOTOVER, keys->col_count);
}

void	ft_key_basic(t_img *keys, int keycode)
{
	keys->move_count++;
	keys->pos_x = keys->player_pos_x;
	keys->pos_y = keys->player_pos_y;
	if (keycode == KEY_W)
	{
		keys->player_pos_y = keys->player_pos_y - keys->img_height;
		keys->player_i--;
	}
	if (keycode == KEY_S)
	{
		keys->player_pos_y = keys->player_pos_y + keys->img_height;
		keys->player_i++;
	}
	if (keycode == KEY_A)
	{
		keys->player_pos_x = keys->player_pos_x - keys->img_width;
		keys->player_j--;
	}
	if (keycode == KEY_D)
	{
		keys->player_pos_x = keys->player_pos_x + keys->img_width;
		keys->player_j++;
	}
}

void	ft_key_img_push(t_img *keys)
{
	mlx_put_image_to_window(keys->mlx_ptr, keys->mlx_win, keys->player, \
	keys->player_pos_x, keys->player_pos_y);
	mlx_put_image_to_window(keys->mlx_ptr, keys->mlx_win, keys->ground, \
	keys->pos_x, keys->pos_y);
	ft_printf("Number of moves: %d\n", keys->move_count);
}
