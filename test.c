/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:12:17 by fllanet           #+#    #+#             */
/*   Updated: 2022/10/11 13:16:04 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	int fd;
	
	fd = open("primitif.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	return (0);
}