#include "so_long.h"

void	map_build(t_img *game)
{
	int	i = 0;
	int	j = 0;

	game->win_width = game->max_x * 50;
	game->win_height = game->max_y * 50;
	ft_printf("win width: %d, win height: %d\n", game->win_width, game->win_height);
	game->pos_x = 1;
	game->pos_y = 1;
	game->mlx_ptr = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->win_width, game->win_height, "so_long v0.3");
	open_xpm(game);

	while (game->map && i < game->max_y)
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->wall, game->pos_x, game->pos_y);
				game->pos_x += 50;
			}
			if (game->map[i][j] == '0')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->ground, game->pos_x, game->pos_y);
				game->pos_x += 50;
			}
			if (game->map[i][j] == 'C')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->collectible, game->pos_x, game->pos_y);
				game->pos_x += 50;
				game->col_count++;
			}
			if (game->map[i][j] == 'E')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->exit, game->pos_x, game->pos_y);
				game->pos_x += 50;
			}
			if (game->map[i][j] == 'P')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->player, game->pos_x, game->pos_y);
				game->player_i = i;
				game->player_j = j;
				game->player_pos_x = game->pos_x;
				game->player_pos_y = game->pos_y;
				game->pos_x += 50;
			}
			j++;
		}
		game->pos_y += 50;
		game->pos_x = 1;
		j = 0;
		i++;
	}
}
