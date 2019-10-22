/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:43:16 by douatla           #+#    #+#             */
/*   Updated: 2019/10/22 12:20:27 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static int		end_of_file = 0;
	char		buffer_file[BUFFER_SIZE + 1];
	char		*tmp_line;
	int			i;

	if (end_of_file == 0)
	{
		end_of_file = read(fd, buffer_file, BUFFER_SIZE);
		buffer_file[end_of_file] = '\0';
	}


	printf("buffer : \n%s\n", buffer_file);
	tmp_line = find_line(buffer_file);
	printf("tmp_line : %s\n", tmp_line);
	
	i = -1;
	while (tmp_line[++i]);
	if(!(*line = (char*)malloc(sizeof(char) * (i + 1))))
		return (-1);
	
	i = -1;
	while(tmp_line[++i])
		line[0][i] = tmp_line[i];
	line[0][i] = '\0';
	
	free(*line);
	return (1);
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
	
	return (0);
}