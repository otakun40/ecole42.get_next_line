/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:55:08 by pjacoby           #+#    #+#             */
/*   Updated: 2021/11/07 00:30:01 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_rem(char	**remainder, char **result)
{
	char	*nl_pos;
	char	*temp;

	if (!remainder || !*remainder)
	{
		*result = NULL;
		return (NULL);
	}
	nl_pos = ft_strchr(*remainder, '\n');
	if (nl_pos)
	{
		temp = *remainder;
		*remainder = ft_strdup(nl_pos + 1);
		*(nl_pos + 1) = '\0';
		*result = ft_strdup(temp);
		free(temp);
		return (nl_pos);
	}
	*result = ft_strdup(*remainder);
	free(*remainder);
	*remainder = NULL;
	return (nl_pos);
}

void	set_result(char *nl_pos, char *buf,
				   char **remainder, char **result)
{
	char	*temp;
	char	*temp2;

	if (nl_pos)
	{
		*remainder = ft_strdup(nl_pos + 1);
		temp = *result;
		*(nl_pos + 1) = '\0';
		temp2 = ft_strdup(buf);
		*result = ft_strjoin(*result, temp2);
		free(temp2);
		free (temp);
		return ;
	}
	temp = *result;
	*result = ft_strjoin(*result, buf);
	free(temp);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*result;
	static char	*remainder;
	char		*nl_pos;
	int			rd;

	if (fd < 0)
		return (NULL);
	nl_pos = check_rem(&remainder, &result);
	while (!nl_pos)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == 0)
			break ;
		else if (rd < 0)
			return (NULL);
		buf[rd] = '\0';
		nl_pos = ft_strchr(buf, '\n');
		set_result(nl_pos, buf, &remainder, &result);
	}
	return (result);
}
