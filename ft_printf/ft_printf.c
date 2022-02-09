/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 18:16:10 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/01/27 10:59:29 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *inputstrings, ...)
{
	va_list		arguments;

	ft_count(-1);
	va_start (arguments, inputstrings);
	while (*inputstrings)
	{
		if (*inputstrings == '%')
		{
			ft_spec_conv(inputstrings, arguments);
			inputstrings++;
		}
		else
			ft_putchar(*inputstrings);
		inputstrings++;
	}
	va_end(arguments);
	return (ft_count(0));
}
