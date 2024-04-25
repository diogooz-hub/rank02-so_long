/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 23:24:49 by dpaco             #+#    #+#             */
/*   Updated: 2023/05/24 23:06:51 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

void	ft_putchar(char c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putnbr(int n, int *count);
void	ft_putnbru(unsigned int n, int *count);
void	ft_pointer(unsigned long p, int *count);
void	ft_convert_int(unsigned int n, char c, int *count);
void	ft_aux1(char c, unsigned int u, int *count);
void	ft_aux2(char c, int n, int *count);
void	ft_aux3(unsigned long p, int *count);
void	ft_aux_printf(const char *format, va_list args, int *count);

int		ft_strlen(const char *str);
int		ft_printf(const char *format, ...);

#endif