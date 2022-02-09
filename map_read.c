/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 12:45:18 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/02/09 13:50:36 by mvan-der      ########   odam.nl         */
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

char			*map_read(char *file)
{
	int		fd;
	int		size;
	char	*output;
	int		ret;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	size = size_count(fd);
	close(fd);
	output = ft_calloc(sizeof(char), size + 1);
	fd = open(file, O_RDONLY);
	ret = read(fd, output, size);
	close(fd);
	return (output);
}
