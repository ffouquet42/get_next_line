/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:54:19 by fllanet           #+#    #+#             */
/*   Updated: 2022/10/12 15:09:32 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*line;
	int				readed;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	readed = 1;
	line = NULL;
	// 1. read from fd and add to linked list
	read_and_stash(fd, &stash, &readed);
	if (stash == NULL)
		return (NULL);
	// 2. extract from stash to line
	extract_line(stash, &line);
	// 3. clean up stash
	clean_stash(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line); 
}


/* Uses read() to add characters to the stash. */

void	read_and_stash(int fd, t_list **stash, int *readed_ptr)
{
	char	*buff;
	
	while (!found_newline(*stash) && *readed_ptr != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return;
		*readed_ptr = (int)read(fd, buff, BUFFER_SIZE);
		if ((*stash == NULL && *readed_ptr == 0) || *readed_ptr == -1)
		{
			free(buff);
			return;
		}
		buff[*readed_ptr] = '\0';
		add_to_stash(stash, buff, readed_ptr);
		free(buff);
	}
}


/* Adds the content of our buffer to the end of our stash. */

void	add_to_stash(t_list **stash, char *buff, int readed)
{
	t_list	*last;
	t_list	*new_node;
	int		i;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (readed + 1));
	if (new_node->content == NULL)
		return;
	i = 0;
	while (buff[i] && i < readed)
	{
		new_node->content[i] = buff[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new_node;
		return;
	}
	last = ft_lst_get_last(*stash);
	last->next = new_node;
}


/* Extracts all characters from our stash and stores them in out line.
 * stopping after the first \n it encounters. */

void	extract_line(t_list *stash, char **line)
{
	int	i;
	int	j;

	if (stash == NULL)
		return;
	generate_line(line, stash);
	if (!*line) // if (*line == NULL)
		return;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}


/* After extracting the line that was read, we don't need those characters anymore.
 * This function clears the stash so only the characters that have not been returned at
 * the end of get_next_line() remain in our static stash. */

void	clean_stash(t_list **stash)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (!clean_node || !stash)
		return;
	clean_node->next = NULL;
	last = ft_lst_get_last(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * ((ft_strlen(last->content) - i) + 1));
	if (!clean_node->content)
		return;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_stash(*stash);
	*stash = clean_node;
}
