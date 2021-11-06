/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 03:44:57 by pjacoby           #+#    #+#             */
/*   Updated: 2021/11/06 03:53:01 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t    i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char    *ft_strdup(const char *s)
{
	char    *result;
	int        i;

	i = 0;
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

void    *ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t    i;
	char    *d;
	char    *s;

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

char    *ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s)
		s++;
	if (c != 0 && *(char *)s == 0)
		return (0);
	return ((char *)s);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
	char    *substring;
	size_t    i;
	size_t    slen;
	size_t    substringlen;

	i = 0;
	if (!s)
		return (0);
	slen = ft_strlen((char *)s);
	if (len == 0 || start > slen)
		substringlen = 0;
	else if (start + len > slen)
		substringlen = slen - start;
	else
		substringlen = len;
	substring = (char *)malloc(sizeof(char) * (substringlen + 1));
	if (substring)
	{
		substring[substringlen] = 0;
		while (i < substringlen)
			substring[i++] = s[start++];
	}
	return (substring);
}


