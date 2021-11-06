/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:55:08 by pjacoby           #+#    #+#             */
/*   Updated: 2021/11/06 10:55:08 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
	size_t    s1len;
	size_t    s2len;
	char    *temp;
	char    *result;

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

char 	*check_rem(char	**remainder, char **result)
{
	char 	*nl_pos;
	char	*temp;

	if (!remainder || !*remainder)
	{
		*result = NULL;
		return (NULL);
	}
	nl_pos = ft_strchr(*remainder, '\n');
	if (!nl_pos)
	{
		*result = ft_strdup(*remainder);
		free(*remainder);
		*remainder = NULL;
		return (nl_pos);
	}
	*result = ft_substr(*remainder, 0, (nl_pos - *remainder + 1));
	temp = * remainder;
	*remainder = ft_strdup(nl_pos + 1);
	free(temp);
	return (nl_pos);
}

char    *get_next_line(int fd)
{
	char    	buf[BUFFER_SIZE + 1];
	char    	*result;
	static char	*remainder;
	char		*nl_pos;
	size_t		rd;
	char 		*temp;

	nl_pos = check_rem(&remainder, &result);
	while (!nl_pos && (rd = read(fd, buf, BUFFER_SIZE)))
	{
		buf[rd] = 0;
		nl_pos = ft_strchr(buf, '\n');
		if (nl_pos)
		{
			remainder = ft_strdup(nl_pos + 1);
			temp = result;
			result = ft_strjoin(result, ft_substr(buf, 0, nl_pos - buf + 1));
			free (temp);
			return (result);
		}
		temp = result;
		result = ft_strjoin(result, buf);
		free(temp);
	}
	return (result);
}