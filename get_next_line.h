/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:53:20 by fllanet           #+#    #+#             */
/*   Updated: 2022/10/13 14:33:02 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*merge_stash_and_buff(char *stash, char *buff);
char	*buff_to_stash(char *buff);
int		ft_strlen(char *str);
int		search_newline(const char *buff);
char	*stash_to_line(char *stash, char *buf);

#endif