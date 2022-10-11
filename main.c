/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:29:01 by fllanet           #+#    #+#             */
/*   Updated: 2022/10/11 15:26:28 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	char *line;

	fd = open("primitif.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		if (line == NULL)
			break;
	}
	return (0);
}