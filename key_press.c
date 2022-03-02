/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_press.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 12:28:52 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/02 12:50:05 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	ft_key_coll(t_img *keys)
// {

// }

// void	ft_key_exit(t_img *keys)
// {

// }
*/
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
	if (keycode == KEY_A)
	{
		keys->player_pos_y = keys->player_pos_y + keys->img_height;
		keys->player_i++;
	}
	if (keycode == KEY_S)
	{
		keys->player_pos_y = keys->player_pos_x - keys->img_width;
		keys->player_j--;
	}
	if (keycode == KEY_D)
	{
		keys->player_pos_y = keys->player_pos_x + keys->img_width;
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