/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:29:01 by fllanet           #+#    #+#             */
/*   Updated: 2022/10/17 13:50:03 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open("file_1.txt", O_RDONLY);
	// fd = 10;
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		// printf("%s", line);
		if (line == NULL)
		{
			free(line);
			break ;
		}
		printf("%s", line);
		free(line);
	}
	return (0);
}

/*
int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		// printf("%s", line);
		if (line == NULL)
		{
			free(line);
			break ;
		}
		printf("%s", line);
		free(line);
	}
	return (0);
}
*/