/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_read.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 12:45:18 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/02/15 14:41:52 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_walls_check(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	map->map = ft_split(map->output, '\n');
	while (map->map[i][j])
	{
		if (map->map[i][j] != '1')
			return (1);
		j++;
	}
	j--;
	while (map->map[i])
	{
		if (map->map[i][j] != '1')
			return (1);
		i++;
	}
	i--;
	while (j > 0)
	{
		if (map->map[i][j] != '1')
			return (1);
		j--;
	}
	while (i > 0)
	{
		if (map->map[i][j] != '1')
			return (1);
		i--;
	}
	return (0);
}

static int	map_objectives_check(char *check)
{
	if (!ft_strchr(check, 'P'))
		return (1);
	if (!ft_strchr(check, 'E'))
		return (1);
	if (!ft_strchr(check, 'C'))
		return (1);
	else
		return (0);
}

static int	size_count(char *file)
{
	int		fd;
	int		count;
	int		ret;
	char	buffer[256];

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("%s", MAPERROR);
		return (0);
	}
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

int	map_read(char *file, t_map *map)
{
	int		fd;
	int		ret;

	map->output = ft_calloc(sizeof(char), size_count(file) + 1);
	fd = open(file, O_RDONLY);
	ret = read(fd, map->output, size_count(file));
	close(fd);
	if (map_objectives_check(map->output) == 0 && map_walls_check(map) == 0)
		return (0);
	else
		return (1);
}
