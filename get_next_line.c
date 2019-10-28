/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:43:16 by douatla           #+#    #+#             */
/*   Updated: 2019/10/23 11:50:52 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char	*buffer[BUFFER_SIZE + 1];
	int		i;
	int		fd;

	i = 0;
	while (i < 5);
	{

		printf("%s\n", buffer);
	}
}

int main(int argc, char **argv)
{
	(void)argc;
	int fd;
	char *line;

	line = NULL;
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	printf("line1 : %s\n\n", line);
	get_next_line(fd, &line);
	printf("line2 : %s\n\n", line);
	get_next_line(fd, &line);
	printf("line3 : %s\n\n", line);
	get_next_line(fd, &line);
	printf("line4 : %s\n\n", line);
	get_next_line(fd, &line);
	printf("line5 : %s\n\n", line);
	get_next_line(fd, &line);
	printf("line6 : %s\n\n", line);
	get_next_line(fd, &line);
	printf("line7 : %s\n\n", line);
	get_next_line(fd, &line);
	printf("should'n exist : %s\n\n", line);
	get_next_line(fd, &line);
	printf("should'n exist : %s\n\n", line);
	get_next_line(fd, &line);
	printf("should'n exist : %s\n\n", line);
	
	return (0);
}