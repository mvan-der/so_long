/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 18:16:10 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/16 13:34:06 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count(int plus)
{
	static int	count = 0;

	if (plus == 0)
	{
		int total;
		total = count;
		count = 0;
		return (total);
	}
	count = count + plus;
	return (count);
}

int	ft_printf(const char *inputstrings, ...)
{
	va_list		arguments;

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
