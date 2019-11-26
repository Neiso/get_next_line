/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:22:01 by douatla           #+#    #+#             */
/*   Updated: 2019/11/26 11:05:22 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_next_line(int fd, char **line)
{
	int				eof;
	static char		buffer[OPEN_MAX][BUFFER_SIZE + 1] = {{0}};

	if (line == NULL || fd < 0 || BUFFER_SIZE == 0 || fd > OPEN_MAX)
		return (-1);
	*line = NULL;
	if (search_line_break(buffer[fd]))
		*line = line_break_in_buffer(buffer[fd], *line);
	eof = -1;
	while (eof != 0 && !(search_line_break(buffer[fd])))
	{
		eof = read(fd, buffer[fd], BUFFER_SIZE);
		if (eof == -1)
			return (-1);
		buffer[fd][eof] = '\0';
		free(*line);
		*line = fill_line(buffer[fd], *line);
		if (search_line_break(buffer[fd]))
			break ;
	}
	if (*line == NULL)
		write(1, "An error occured", 16);
	if (eof == 0)
		return (0);
	return (1);
}
