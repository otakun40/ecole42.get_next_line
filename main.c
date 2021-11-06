/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:40:02 by pjacoby           #+#    #+#             */
/*   Updated: 2021/11/06 04:15:43 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int main()
{
	char *result;
	int fd = open("text.txt", O_RDONLY);

	while ((result = get_next_line(fd)))
		printf("%s\n", result);
}