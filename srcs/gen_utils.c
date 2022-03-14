/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gen_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/15 14:35:52 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/14 13:28:29 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_charpos(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	ft_strcheck(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			return (0);
		i++;
	}
	return (1);
}

static void	ft_free_array(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

void	ft_free_map(t_img *game)
{
	ft_free_array(game->map);
	free(game->output);
	free(game);
}

void	ft_load_images(t_img *game)
{
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "./img/wall.xpm", \
	&game->img_width, &game->img_height);
	game->ground = mlx_xpm_file_to_image(game->mlx_ptr, "./img/ground.xpm", \
	&game->img_width, &game->img_height);
	game->coll = mlx_xpm_file_to_image(game->mlx_ptr, "./img/collectible.xpm", \
	&game->img_width, &game->img_height);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr, "./img/exit.xpm", \
	&game->img_width, &game->img_height);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, "./img/player.xpm", \
	&game->img_width, &game->img_height);
	if (!game->wall || !game->ground || !game->coll || !game->exit || \
	!game->player)
	{
		ft_printf("\033[0;31m%s\e[0m", IMGERROR);
		exit(0);
	}
}
