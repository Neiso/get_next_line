/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:43:16 by douatla           #+#    #+#             */
/*   Updated: 2019/10/21 15:45:09 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static int size;
	static char buffer[BUFFER_SIZE];
	static int i;

	if (!buffer)
		
	return (1);
}

int main(int argc, char **argv)
{
	(void)argc;
	int fd;
	char **tab;

	tab = (char**)malloc(sizeof(char*) * 100);

	fd = open(argv[1], O_RDONLY);
	
	get_next_line(fd, tab);
	
	return (0);
}