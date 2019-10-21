/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:43:16 by douatla           #+#    #+#             */
/*   Updated: 2019/10/19 19:16:48 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
    int static	line_nb;
	char		buffer[];
	int 		eof;

	eof = read(fd, buffer, 20);
    buffer[eof - 1] = '\0';
	line = 0;
	printf("%s", buffer);
	return (0);
}

int main(int argc, char **argv)
{
	(void)argc;
	int fd;
	char **tab;

	tab = (char**)malloc(sizeof(char*) * 100);
	fd = open("test.txt", O_RDONLY);
	get_next_line(fd, tab);
}