/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_stuff.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/15 14:35:52 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/01 12:48:17 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
