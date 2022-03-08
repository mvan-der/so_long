/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 12:45:18 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/08 12:05:41 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_strcheck(char *s, int c)
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

static int	ft_map_walls_check(t_img *game)
{
	int		i;

	i = 0;
	if (!ft_strcheck(game->map[i], '1'))
		return (1);
	game->max_x = 0;
	while (game->map[i])
	{
		if (game->map[i][game->max_x] != '1')
			return (1);
		i++;
	}
	game->max_y = i;
	i--;
	game->max_x = ft_strlen(game->map[i]);
	if (!ft_strcheck(game->map[i], '1'))
		return (1);
	while (i > 0)
	{
		if (game->map[i][game->max_x - 1] != '1')
			return (1);
		i--;
	}
	return (0);
}

static int	ft_char_check(char *check)
{
	int		i;
	char	set[7];

	i = 0;
	ft_strlcpy(set, "01CEP\n", 7);
	while (check[i])
	{
		if (!ft_strchr(set, check[i]))
			return (1);
		if (check[i] == 'E')
		{
			set[ft_charpos(set, 'E')] = set[ft_strlen(set) - 1];
			set[ft_strlen(set) - 1] = '\0';
		}
		if (check[i] == 'P')
		{
			set[ft_charpos(set, 'P')] = set[ft_strlen(set) - 1];
			set[ft_strlen(set) - 1] = '\0';
		}
		i++;
	}
	return (0);
}

static int	ft_map_size(char *file)
{
	int		fd;
	int		count;
	int		ret;
	char	buffer[256];

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	count = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buffer, 256);
		count += ret;
	}
	close (fd);
	return (count);
}

int	ft_map_read(char *file, t_img *game)
{
	int		fd;
	int		ret;

	game->output = ft_calloc(sizeof(char), ft_map_size(file) + 1);
	fd = open(file, O_RDONLY);
	ret = read(fd, game->output, ft_map_size(file));
	close(fd);
	game->map = ft_split(game->output, '\n');
	if (!game->map)
	{
		ft_free_map(game);
		return (1);
	}
	if (ft_char_check(game->output) == 0 && ft_map_walls_check(game) == 0)
		return (0);
	else
		return (1);
}
