/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:43:16 by douatla           #+#    #+#             */
/*   Updated: 2019/10/29 10:05:00 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**	There are two cases scenarios :
**		-The buffer is empty or clean so it will enter the WHILE loop and gets
**		  filled up by the READ function. Then the input LINE will be write up
**		  till a line break is found in the buffer. Then, it gets out from the
**		  WHILE loop
**
**		-The buffer is not clean so there are still lines breaks in it. So it
**		  will fill up multiples lines as long as the function is called and the
**		  buffer is not clean. It won't be any more READ call until the buffer
**		  is entirely clean.
*/

int		get_next_line(int fd, char **line)
{
	int				eof;
	static char		buffer[BUFFER_SIZE + 1] = {0};

	if (fd < 0)
		return (-1);
	*line = NULL;
	if (search_line_break(buffer))
		*line = line_break_in_buffer(buffer, *line);
	eof = -1;
	while (eof != 0 && !(search_line_break(buffer)))
	{
		eof = read(fd, buffer, BUFFER_SIZE);
		if (eof == -1)
			return (-1);
		printf("eof : %d\n", eof);
		buffer[eof] = '\0';
		*line = fill_line(buffer, *line);
		if (search_line_break(buffer))
			break ;
	}
	if (*line == NULL)
		return (-1);
	if (eof == 0)
		return (0);
	free(*line);
	return (1);
}

int main(int argc, char **argv)
{
	(void)argc;
	int fd;
	char *line;
	
	fd = open(argv[1], O_RDONLY);
	printf("return value : %d\n", get_next_line(fd, &line));
	printf("line final 1 : %s\n", line);
	get_next_line(fd, &line);
	// printf("line final 2 : %s\n", line);
	// get_next_line(fd, &line);
	// printf("line final 3 : %s\n", line);
	// get_next_line(fd, &line);
	// printf("line final 4 : %s\n", line);
	// get_next_line(fd, &line);
	// printf("line final 5 : %s\n", line);
	// get_next_line(fd, &line);
	// printf("line final 6 : %s\n", line);
}