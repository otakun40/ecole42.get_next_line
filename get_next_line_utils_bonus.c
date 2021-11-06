/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 03:44:57 by pjacoby           #+#    #+#             */
/*   Updated: 2021/11/07 01:08:05 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*result;
	int		i;

	i = 0;
	if (!s || !*s)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (result != NULL)
	{
		while (s[i])
		{
			result[i] = s[i];
			i++;
		}
		result[i] = 0;
	}
	return (result);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	if (src || dst)
	{
		d = (char *)dst;
		s = (char *)src;
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
		return (dst);
	}
	else
		return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s)
		s++;
	if (c != 0 && *(char *)s == 0)
		return (0);
	return ((char *)s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*temp;
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	temp = result;
	if (result)
	{
		ft_memcpy(temp, s1, s1len);
		temp += s1len;
		ft_memcpy(temp, s2, s2len);
		temp += s2len;
		*temp = 0;
	}
	return (result);
}
