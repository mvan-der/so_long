/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 10:51:43 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/01 16:55:01 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#define MAPERROR "Invalid map\n"
#define GAMEWIN "Congratulations! You have won the game!"

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "./mlx/mlx.h"
#include "./ft_printf/ft_printf.h"


typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx_ptr;
	void	*mlx_win;
	int		win_width;
	int		win_height;
	int		pos_x;
	int		pos_y;
	int		max_x;
	int		max_y;
	int		img_width;
	int		img_height;
	char	*output;
	char	**map;
	void	*wall;
	void	*ground;
	void	*collectible;
	void	*exit;
	void	*player;
	int		player_i;
	int		player_j;
	int		player_pos_x;
	int		player_pos_y;
	int		move_count;
	int		col_count;
}				t_img;

int		map_read(char *file, t_img *game);
void	ft_free_map(t_img *game);
void	map_build(t_img *game);
void	open_xpm(t_img *game);
int		close_window(t_img *release);
int		key_press(int keycode, t_img *keys);
#endif
