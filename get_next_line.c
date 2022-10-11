/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:54:19 by fllanet           #+#    #+#             */
/*   Updated: 2022/10/11 15:45:53 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;
	int				readed;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	readed = 1;
	line = NULL;
	// 1. read from fd and add to linked list
	read_and_stash(fd, &stash, &readed)
	// 2. extract from stash to line
	// 3. clean up stash
	return (line);
}

void read_and_stash(int fd, t_list **stash, int *readed_ptr)
{
	char *buf;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!found_newline(*stash) && *readed_ptr != 0)
	{
		*readed_ptr = (int)read(fd, buf, BUFFER_SIZE);
		if ((*stash == NULL && *readed_ptr == 0) || *readed_ptr == -1) // <= 0 ?
		{
			free(buf);
			return;
		}
		buf[*readed_ptr] = '\0';
	}
}