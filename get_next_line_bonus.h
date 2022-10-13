/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:12:31 by fllanet           #+#    #+#             */
/*   Updated: 2022/10/13 16:16:06 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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