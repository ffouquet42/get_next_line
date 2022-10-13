/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:12:58 by fllanet           #+#    #+#             */
/*   Updated: 2022/10/13 16:19:16 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd_1;
	int		fd_2;
	int		fd_3;
	char	*line_1;
	char	*line_2;
	char	*line_3;

	fd_1 = open("file_1.txt", O_RDONLY);
	if (fd_1 == -1)
		return (-1);
	fd_2 = open("file_2.txt", O_RDONLY);
	if (fd_2 == -1)
		return (-1);
	fd_3 = open("file_3.txt", O_RDONLY);
	if (fd_3 == -1)
		return (-1);
	while (1)
	{
		line_1 = get_next_line(fd_1);
		line_2 = get_next_line(fd_2);
		line_3 = get_next_line(fd_3);
		if (line_1 == NULL && line_2 == NULL && line_3 == NULL)
			break ;
		printf("%s", line_1);
		printf("%s", line_2);
		printf("%s", line_3);
		free(line_1);
		free(line_2);
		free(line_3);
	}
	return (0);
}
