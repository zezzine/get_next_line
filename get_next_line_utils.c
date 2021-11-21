/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:48:43 by zezzine           #+#    #+#             */
/*   Updated: 2021/11/21 17:37:00 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*p;
	int				i;
	int				j;

	i = -1;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = ft_strldup("", 0);
	p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!p)
		return (NULL);
	while (s1[++i])
		p[j++] = s1[i];
	i = -1;
	while (s2[++i])
		p[j++] = s2[i];
	p[j] = 0;
	free(s1);
	return (p);
}

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}	
		i++;
	}
	if (s[i] == (char)c)
	{
		return ((char *)s + i);
	}	
	return (NULL);
}

char	*ft_strldup(char *s1, int len)
{
	char	*p;
	int		i;

	p = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!p)
		return (NULL);
	while (s1[i] && i < len - 1)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
