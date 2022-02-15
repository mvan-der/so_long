/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 10:51:43 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/02/15 14:41:09 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#define MAPERROR "Error\n"

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "./mlx/mlx.h"
#include "./ft_printf/ft_printf.h"

typedef struct	s_map
{
	char	**map;
	char	*output;
}				t_map;

int		map_read(char *file, t_map *test12);
void	ft_free_all(t_map *map);

#endif
