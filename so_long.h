/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 10:51:43 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/02 16:58:46 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define NOMAPERROR "Error: No map or too many maps provided\n"
# define MAPERROR "Error: Invalid map\n"
# define IMGERROR "Error: Image files missing or corrupted\n"
# define GAMEWIN "Congratulations! You have won the game!"
# define GAMENOTOVER "You have not collected all the collectibles yet!"
# define TOTALMOVES "Total number of moves needed: "
# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "./mlx/mlx.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_img
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
	void	*coll;
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
void	ft_map_build(t_img *game);
void	open_xpm(t_img *game);
int		close_window(t_img *release);
int		key_press(int keycode, t_img *keys);
void	ft_init(t_img *game);
void	ft_wall_image(t_img *game);
void	ft_ground_image(t_img *game);
void	ft_coll_image(t_img *game);
void	ft_exit_image(t_img *game);
void	ft_player_image(t_img *game, int i, int j);
void	ft_key_basic(t_img *keys, int keycode);
void	ft_key_img_push(t_img *keys);
#endif
