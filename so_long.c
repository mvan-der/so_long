/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 10:46:48 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/02/15 14:39:18 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		check;
	t_map	*map;

	map = (t_map *) malloc(sizeof(t_map));
	if (argc != 2)
	{
		ft_printf("No map provided or too many maps provided\n");
		return (0);
	}
	check = map_read(argv[1], map);
	if (check == 1)
	{
		ft_printf("%s", MAPERROR);
		ft_free_all(map);
		return (0);
	}
	else
	{
		ft_printf("Succes\n");
		ft_free_all(map);
		return (0);
	}
}
