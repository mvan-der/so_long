/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_uxX.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:36:57 by mvan-der      #+#    #+#                 */
/*   Updated: 2021/12/22 14:00:43 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_u(va_list arguments)
{
	unsigned int	j;
	char			*str;

	j = va_arg(arguments, int);
	str = ft_utoa_printf(j, 10, 'u');
	ft_putstr(str);
	free(str);
}

void	ft_conv_x(va_list arguments)
{
	unsigned int	j;
	char			*str;

	j = va_arg(arguments, int);
	str = ft_utoa_printf(j, 16, 'x');
	ft_putstr(str);
	free(str);
}

void	ft_conv_x2(va_list arguments)
{
	unsigned int	j;
	char			*str;

	j = va_arg(arguments, int);
	str = ft_utoa_printf(j, 16, 'X');
	ft_putstr(str);
	free(str);
}
