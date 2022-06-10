/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:29:01 by fllanet           #+#    #+#             */
/*   Updated: 2022/06/10 08:32:20 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int fd = 1;
	write(1, "start\n", 6); // debug
	printf("%s", get_next_line(fd));
	write(1, "end\n", 4); // debug
	return (0);
}