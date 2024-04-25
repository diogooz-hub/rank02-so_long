/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:59:32 by dpaco             #+#    #+#             */
/*   Updated: 2023/05/24 23:07:47 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_aux1(char c, unsigned int u, int *count)
{
	if (c == 'u')
		ft_putnbru(u, count);
	if (c == 'x' || c == 'X')
		ft_convert_int(u, c, count);
}

void	ft_aux2(char c, int n, int *count)
{
	if (c == 'd' || c == 'i')
		ft_putnbr(n, count);
	if (c == 'c')
		ft_putchar((char)(n), count);
}

void	ft_aux3(unsigned long p, int *count)
{
	if (p == 0)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	else
	{
		ft_putstr("0x", count);
		ft_pointer(p, count);
	}
}
