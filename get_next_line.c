/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:54:19 by fllanet           #+#    #+#             */
/*   Updated: 2022/06/10 08:33:59 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*buf_to_stash(char *buf, char *stash)
{
	char	*dest;
	size_t	size_to_malloc;
	size_t	i;
	size_t	y;

	size_to_malloc = ft_strlen(buf) + ft_strlen(stash);
	dest = malloc(sizeof(char) * (size_to_malloc + 1));
	if (!dest)
		return (NULL);
	i = 0;
	y = 0;
	while (buf[i])
	{
		dest[i] = buf[i];
		i++;
	}
	while (stash[y])
	{
		dest[i] = stash[y];
		i++;
		y++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	size_t buffer_size = 5; // delete
	
	char		*buf;
	static char	*stash;

	write(1, "1\n", 2); // debug
	
	buf = malloc(sizeof(char) * (buffer_size + 1));
	if (!buf)
		return (NULL);
		
	write(1, "2\n", 2); // debug
	
	read(fd, buf, buffer_size);
	
	write(1, "3\n", 2); // debug

	stash = buf_to_stash(buf, stash);
}