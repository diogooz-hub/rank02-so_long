/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 23:28:52 by dpaco             #+#    #+#             */
/*   Updated: 2023/05/23 23:00:57 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbru(unsigned int n, int *count)
{
	if (n <= UINT_MAX)
	{
		if (n > 9)
		{
			ft_putnbru((n / 10), count);
			ft_putnbru((n % 10), count);
		}
		else
		{
			ft_putchar((n + '0'), count);
		}
	}
}

void	ft_convert_int(unsigned int n, char c, int *count)
{
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (n < 16)
		ft_putchar(base[n], count);
	if (n >= 16)
	{
		ft_convert_int (n / 16, c, count);
		ft_convert_int (n % 16, c, count);
	}
}

void	ft_pointer(unsigned long p, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (p < 16)
		ft_putchar(base[p], count);
	if (p >= 16)
	{
		ft_pointer (p / 16, count);
		ft_pointer (p % 16, count);
	}
}
