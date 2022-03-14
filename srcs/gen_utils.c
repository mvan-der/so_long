/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gen_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/15 14:35:52 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/14 15:11:38 by mvan-der      ########   odam.nl         */
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

char	*ft_strstr(const char *big, const char *little)
{
	char	*pbig;
	size_t	i;
	size_t	j;

	pbig = (char *)big;
	i = 0;
	if (little[i] == '\0')
		return (pbig);
	while (pbig[i] != '\0')
	{
		j = 0;
		while (pbig[i + j] == little[j])
		{
			if (little[j + 1] == '\0')
				return (&pbig[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
