/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 10:46:48 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/02/09 13:50:34 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_printf("No map provided or too many maps provided\n");
		return (0);
	}
	char *str;

	str = map_read(argv[1]);
	ft_printf("%s\n", str);
	// ft_printf("%c\n", str[33]);
	// ft_printf("%c\n", str[34]);
	// ft_printf("%c\n", str[35]);
	return (0);
}
