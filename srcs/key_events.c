/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_events.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 08:59:23 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/03 12:13:55 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_key_w(t_img *keys, int keycode)
{
	if (keys->map[keys->player_i - 1][keys->player_j] == '1')
		return (0);
	if (keys->map[keys->player_i - 1][keys->player_j] == 'C')
		ft_key_coll(keys, keycode);
	if (keys->map[keys->player_i - 1][keys->player_j] == 'E')
		ft_key_exit(keys);
	ft_key_basic(keys, keycode);
	ft_key_img_push(keys);
	return (0);
}

int	ft_key_s(t_img *keys, int keycode)
{
	if (keys->map[keys->player_i + 1][keys->player_j] == '1')
		return (0);
	if (keys->map[keys->player_i + 1][keys->player_j] == 'C')
		ft_key_coll(keys, keycode);
	if (keys->map[keys->player_i + 1][keys->player_j] == 'E')
		ft_key_exit(keys);
	ft_key_basic(keys, keycode);
	ft_key_img_push(keys);
	return (0);
}

int	ft_key_a(t_img *keys, int keycode)
{
	if (keys->map[keys->player_i][keys->player_j - 1] == '1')
		return (0);
	if (keys->map[keys->player_i][keys->player_j - 1] == 'C')
		ft_key_coll(keys, keycode);
	if (keys->map[keys->player_i][keys->player_j - 1] == 'E')
		ft_key_exit(keys);
	ft_key_basic(keys, keycode);
	ft_key_img_push(keys);
	return (0);
}

int	ft_key_d(t_img *keys, int keycode)
{
	if (keys->map[keys->player_i][keys->player_j + 1] == '1')
		return (0);
	if (keys->map[keys->player_i][keys->player_j + 1] == 'C')
		ft_key_coll(keys, keycode);
	if (keys->map[keys->player_i][keys->player_j + 1] == 'E')
		ft_key_exit(keys);
	ft_key_basic(keys, keycode);
	ft_key_img_push(keys);
	return (0);
}
