/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 01:05:52 by dpaco             #+#    #+#             */
/*   Updated: 2024/01/15 22:32:40 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != 10)
		i++;
	if (str[i] == 10)
		i++;
	return (i);
}

void	ft_bzero(void *dest, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dest + i) = 0;
		i++;
	}
}

int	clean_buf(char *str)
{
	int	i;
	int	n;
	int	nl;

	i = 0;
	n = 0;
	nl = 0;
	while (str[i])
	{
		if (nl == 1)
		{
			str[n] = str[i];
			n++;
		}
		if (str[i] == 10)
			nl = 1;
		str[i] = 0;
		i++;
	}
	return (nl);
}
