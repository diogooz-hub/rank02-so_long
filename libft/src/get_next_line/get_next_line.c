/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaco <dpaco@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:42:22 by dpaco             #+#    #+#             */
/*   Updated: 2024/01/15 22:33:23 by dpaco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*res;
	size_t	i;

	res = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	free(s1);
	while (*s2)
	{
		res[i] = *s2;
		i++;
		if (*s2 == 10)
			break ;
		s2++;
	}
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buf[BUFFER_SIZE + 1];

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		ft_bzero(buf, ft_strlen_gnl(buf));
		return (NULL);
	}
	line = NULL;
	while (*buf || read(fd, buf, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin_gnl(line, buf);
		if (clean_buf(buf) == 1)
			break ;
	}
	return (line);
}

// int main()
// {
// 	int 	fd;
// 	char	*line1;
// 	char	*line2;
// 	char	*line3;
// 	char	*line4;
// 	char	*line5;

// 	fd = open("txt1.txt", O_RDONLY);
// 	line1 = get_next_line(fd);
// 	printf("line1 is: %s\n", line1);
// 	free(line1);
// }

// int main()
// {
// 	while (1)
// 	{
// 		char *line = get_next_line(0);
// 		printf("line: %s\n", line);
// 		if(line == NULL)
// 			return(0);
// 		free (line);
// 	}
// }