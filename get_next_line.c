/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:51:33 by zezzine           #+#    #+#             */
/*   Updated: 2021/11/21 18:34:34 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*get_line(char *s1, int rd)
{
	int		i;
	char	*p;

	i = 0;
	if (s1 == NULL)
		return (0);
	while (s1[i] && s1[i] != '\n')
		i++;
	p = ft_strldup(s1, i + 2);
	if (!p)
		return (NULL);
	if (rd == 0 && ft_strlen(p) == 0)
	{
		free(p);
		return (NULL);
	}
	return (p);
}

char	*get_remember(char *s1)
{
	int		i;
	char	*p;

	i = 0;
	if (s1 == NULL)
		return (0);
	while (s1[i] && s1[i] != '\n')
		i++;
	if (!s1[i])
	{
		free(s1);
		return (NULL);
	}
	i++;
	p = ft_strldup(s1 + i, ft_strlen(s1) - i + 1);
	free(s1);
	return (p);
}

char	*ft_free(char *buffer, char *save)
{
	free(save);
	free(buffer);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*line;
	static char		*save;
	int				rd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rd = 1;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	while (rd != 0 && !ft_strchr(buffer, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
			return (ft_free(buffer, save));
		buffer[rd] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	line = get_line(save, rd);
	save = get_remember(save);
	return (line);
}
/*
int	main(void)
{
	int		fd = open("test", 2);
	char	*line;

	int i = 0;
	//printf("|");
	while(i < 4)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
	//printf("|\n");
	//system("leaks a.out");
}
*/