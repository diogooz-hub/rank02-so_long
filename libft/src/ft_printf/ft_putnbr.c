/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:31:04 by dpaco             #+#    #+#             */
/*   Updated: 2023/05/23 22:53:25 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", count);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', count);
		ft_putnbr(-n, count);
	}
	else if (n > 9)
	{
		ft_putnbr((n / 10), count);
		ft_putnbr((n % 10), count);
	}
	else
	{
		ft_putchar((n + '0'), count);
	}
}
