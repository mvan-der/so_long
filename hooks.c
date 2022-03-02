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
		
		if(keys->map[keys->player_i - 1][keys->player_j] == '1')
			return (0);
		if(keys->map[keys->player_i - 1][keys->player_j] == 'C')
		{
			keys->map[keys->player_i - 1][keys->player_j] = '0';
			keys->col_count--;
			keys->move_count++;
		}
		if(keys->map[keys->player_i - 1][keys->player_j] == 'E')
		{
			if(keys->col_count == 0)
			{
				keys->move_count++;
				ft_printf("Number of moves: %d\n", keys->move_count);
				ft_printf("\033[0;32m%s\e[0m\n", GAMEWIN);
				return (close_window(keys));
			}
			else
			{
				ft_printf("\033[0;31m%s\e[0m\n", GAMENOTOVER);
				return(ft_printf("Number of moves: %d\n", keys->move_count));
			}
		}
			keys->move_count++;
			keys->pos_x = keys->player_pos_x;
			keys->pos_y = keys->player_pos_y;
			keys->player_pos_y = keys->player_pos_y - 50;
			keys->player_i--;
		mlx_put_image_to_window(keys->mlx_ptr, keys->mlx_win, keys->player, keys->player_pos_x, keys->player_pos_y);
		mlx_put_image_to_window(keys->mlx_ptr, keys->mlx_win, keys->ground, keys->pos_x, keys->pos_y);
		ft_printf("Number of moves: %d\n", keys->move_count);
	}
	if (keycode == KEY_A)
	{
		keys->move_count++;
		if(keys->map[keys->player_i + 1][keys->player_j] == '1')
			return(ft_printf("Number of moves: %d\n", keys->move_count));
		if(keys->map[keys->player_i + 1][keys->player_j] == 'C')
		{
			keys->map[keys->player_i + 1][keys->player_j] = '0';
			keys->col_count--;
		}
		if(keys->map[keys->player_i + 1][keys->player_j] == 'E')
		{
			if(keys->col_count == 0)
			{
				ft_printf("\033[0;32m%s\e[0m\n", GAMEWIN);
				close_window(keys);
			}
			else
			{
				ft_printf("\033[0;31mYou have not completed the game yet!\e[0m\n");
				return(ft_printf("Number of moves: %d\n", keys->move_count));
			}
		}
		keys->pos_x = keys->player_pos_x;
		keys->pos_y = keys->player_pos_y;
		keys->player_pos_y = keys->player_pos_y + 50;
		keys->player_i++;
		mlx_put_image_to_window(keys->mlx_ptr, keys->mlx_win, keys->player, keys->player_pos_x, keys->player_pos_y);
		mlx_put_image_to_window(keys->mlx_ptr, keys->mlx_win, keys->ground, keys->pos_x, keys->pos_y);
		ft_printf("Number of moves: %d\n", keys->move_count);
	}
	if (keycode == KEY_S)
	{
		keys->move_count++;
		if(keys->map[keys->player_i][keys->player_j - 1] == '1')
			return(ft_printf("Number of moves: %d\n", keys->move_count));
		if(keys->map[keys->player_i][keys->player_j - 1] == 'C')
		{
			keys->map[keys->player_i][keys->player_j - 1] = '0';
			keys->col_count--;
		}
		if(keys->map[keys->player_i][keys->player_j - 1] == 'E')
		{
			if(keys->col_count == 0)
			{
				ft_printf("\033[0;32m%s\e[0m\n", GAMEWIN);
				close_window(keys);
			}
			else
			{
				ft_printf("\033[0;31mYou have not completed the game yet!\e[0m\n");
				return(ft_printf("Number of moves: %d\n", keys->move_count));
			}
		}
		keys->pos_x = keys->player_pos_x;
		keys->pos_y = keys->player_pos_y;
		keys->player_pos_x = keys->player_pos_x - 50;
		keys->player_j--;
		mlx_put_image_to_window(keys->mlx_ptr, keys->mlx_win, keys->player, keys->player_pos_x, keys->player_pos_y);
		mlx_put_image_to_window(keys->mlx_ptr, keys->mlx_win, keys->ground, keys->pos_x, keys->pos_y);
		ft_printf("Number of moves: %d\n", keys->move_count);
	}
	if (keycode == KEY_D)
	{
		keys->move_count++;
		if(keys->map[keys->player_i][keys->player_j + 1] == '1')
		{
			return(ft_printf("Number of moves: %d\n", keys->move_count));
		}
		if(keys->map[keys->player_i][keys->player_j + 1] == 'C')
		{
			keys->map[keys->player_i][keys->player_j + 1] = '0';
			keys->col_count--;
		}
		if(keys->map[keys->player_i][keys->player_j + 1] == 'E')
		{
			if(keys->col_count == 0)
			{
				ft_printf("\033[0;32m%s\e[0m\n", GAMEWIN);
				close_window(keys);
			}
			else
			{
				ft_printf("\033[0;31mYou have not completed the game yet!\e[0m\n");
				return(ft_printf("Number of moves: %d\n", keys->move_count));
			}
		}
		keys->pos_x = keys->player_pos_x;
		keys->pos_y = keys->player_pos_y;
		keys->player_pos_x = keys->player_pos_x + 50;
		keys->player_j++;
		mlx_put_image_to_window(keys->mlx_ptr, keys->mlx_win, keys->player, keys->player_pos_x, keys->player_pos_y);
		mlx_put_image_to_window(keys->mlx_ptr, keys->mlx_win, keys->ground, keys->pos_x, keys->pos_y);
		ft_printf("Number of moves: %d\n", keys->move_count);
	}
	return (0);
}
