/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 01:17:33 by dpaco             #+#    #+#             */
/*   Updated: 2024/01/15 22:32:24 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

int		ft_strlen_gnl(const char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		clean_buf(char *str);
void	ft_bzero(void *dest, size_t n);
char	*get_next_line(int fd);

#endif