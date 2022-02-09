/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_count.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:16:34 by mvan-der      #+#    #+#                 */
/*   Updated: 2021/12/22 13:55:03 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	ft_reset_count(int count)
{
	if (count == 0)
		return (count);
	count = (count / count) - 1;
	return (count);
}

int	ft_count(int plus)
{
	static int	count = 0;

	if (plus == -1)
	{
		count = ft_reset_count(count);
		return (count);
	}
	count = count + plus;
	return (count);
}
