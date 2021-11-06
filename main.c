/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:58:32 by pjacoby           #+#    #+#             */
/*   Updated: 2021/11/06 20:23:17 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/file.h>
#include "get_next_line.h"

int	main()
{
	char	*result;
	int		fd = open("text.txt", O_RDONLY);
	int i = 1;

	while ((result = get_next_line(fd)))
	{
		printf("%d: %s", i++, result);
		free(result);
	}
	printf("%d: %s", i, result);
	free(result);
	close(fd);

//	printf("%s\n", ft_strdup(""));
}