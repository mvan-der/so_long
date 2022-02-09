/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_read.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 12:45:18 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/02/09 16:50:34 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int		size_count(int fd)
{
	int		count;
	int		ret;
	char	buffer[256];

	count = 0;
	while((ret = read(fd, buffer, 256)))
		count += ret;
	return (count);
}

char			**map_read(char *file)
{
	int		fd;
	int		size;
	char	*output;
	int		ret;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("%s", MAPERROR);
		return (0);
	}
	size = size_count(fd);
	close(fd);
	output = ft_calloc(sizeof(char), size + 1);
	fd = open(file, O_RDONLY);
	ret = read(fd, output, size);
	close(fd);
	if (!ft_strchr(output, 'P'))
		{
			ft_printf("%s", MAPERROR);
			return (0);
		}
	if (!ft_strchr(output, 'E'))
		{
			ft_printf("%s", MAPERROR);
			return (0);
		}
	if (!ft_strchr(output, 'C'))
		{
			ft_printf("%s", MAPERROR);
			return (0);
		}
	
	char	**map;
	map = ft_split(output, '\n');
	int i = 0;
	int j = 0;

	while (map[i][j])
	{
		if (map[i][j] != '1')
		{
			ft_printf("%s", MAPERROR);
			return (0);
		}
		j++;
	}
	ft_printf("loop 1: %d, %d\n", i, j);
	j--;
	while (map[i])
	{
		if (map[i][j] != '1')
		{
			ft_printf("%s", MAPERROR);
			return (0);
		}
		i++;
	}
	ft_printf("loop 2: %d, %d\n", i, j);
	i--;
	while (j > 0)
	{
		if (map[i][j] != '1')
		{
			ft_printf("%s", MAPERROR);
			return (0);
		}
		j--;
	}
	ft_printf("loop 3: %d, %d\n", i, j);
	while (i > 0)
	{
		if (map[i][j] != '1')
		{
			ft_printf("%s", MAPERROR);
			return (0);
		}
		i--;
	}
	ft_printf("loop 4: %d, %d\n", i, j);
	return (map);
}
