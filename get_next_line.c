/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:54:19 by fllanet           #+#    #+#             */
/*   Updated: 2022/10/12 17:56:09 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	char		*stash;
	int			read_count;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	read_count = BUFFER_SIZE;
	stash = NULL;
	stash = ft_strjoin(stash, buff); // -> strdup de buff ?
	while (read_count == BUFFER_SIZE && search_newline(buff) != 1) // !search_newline()
	{
		read_count = read(fd, buff, BUFFER_SIZE);
		// ?
		if (read_count == -1) 
			return (free(stash), NULL);
		buff[read_count] = '\0';
		if (read_count == 0 && !stash[0])
			return (free(stash), NULL);
		stash = ft_strjoin(stash, buff);
		// ?
	}
	line = ft_clean(stash, buff);
	return(free(stash), line);
}

char	*ft_strjoin(char *stash, char *buff)
{
	int		i;
	int		j;
	int		len; // -> size_t ?
	char	*dest;

	if (!stash)
		return (ft_strdup(buff));
	len = ft_strlen(stash) + ft_strlen(buff);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (stash[i])
	{
		dest[i] = stash[i];
		i++;
	}
	j = 0;
	while (buff[j])
	{
		dest[i + j] = buff[j];
		j++;
	}
	dest[i + j] = '\0';
	free(stash);
	return (dest);
}

char	*ft_strdup(char *buff)
{
	int		i;
	char	*dest;

	dest = malloc(sizeof(char) * (ft_strlen(buff) + 1));
	if (!dest)
		return (0); // ? | -> NULL ?
	i = 0;
	while (buff[i])
	{
		dest[i] = buff[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
//	if (!str)
//		return (0);
	while (str[i])
		i++;
	return (i);
}

int	search_newline(const char *buff)
{
	int	i;

//	if (!buff)
//		return (0);
	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_clean(char *stash, char *buf)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	j = 0;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (j < i && stash[j])
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	j = 0;
	while (stash[i] && buf[j])
		buf[j++] = stash[i++];
	buf[j] = '\0';
	return (line);
}