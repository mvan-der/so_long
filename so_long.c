/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 10:46:48 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/02/09 16:03:52 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("No map provided or too many maps provided\n");
		return (0);
	}
	char **str;

	str = map_read(argv[1]);
	// ft_printf("%s\n", str[0][0]);
	
	
	
	return (0);
}
