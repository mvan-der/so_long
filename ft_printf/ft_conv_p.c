/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conv_p.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 18:47:04 by mvan-der      #+#    #+#                 */
/*   Updated: 2021/12/22 13:56:26 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_p(va_list arguments)
{
	void				*p;
	unsigned long int	i;
	char				*str;
	char				*res;

	p = va_arg(arguments, void *);
	if (p == NULL)
	{
		ft_putstr("0x0");
		return ;
	}
	i = (unsigned long int) p;
	str = ft_utoa_printf(i, 16, 'x');
	res = ft_strjoin("0x", str);
	ft_putstr(res);
	free(str);
	free(res);
}
