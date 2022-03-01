#include "so_long.h"

void	open_xpm(t_img *game)
{
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "./img/wall2.xpm", &game->img_width, &game->img_height);
	game->ground = mlx_xpm_file_to_image(game->mlx_ptr, "./img/ground.xpm", &game->img_width, &game->img_height);;
	game->collectible = mlx_xpm_file_to_image(game->mlx_ptr, "./img/collectible.xpm", &game->img_width, &game->img_height);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr, "./img/exit.xpm", &game->img_width, &game->img_height);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, "./img/player.xpm", &game->img_width, &game->img_height);
}
