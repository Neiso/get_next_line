/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:43:16 by douatla           #+#    #+#             */
/*   Updated: 2019/11/25 14:20:25 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int				eof;
	static char		buffer[BUFFER_SIZE + 1] = {0};

	if (line == NULL || fd < 0 || BUFFER_SIZE == 0)
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
		buffer[eof] = '\0';
		free(*line);
		*line = fill_line(buffer, *line);
		if (search_line_break(buffer))
			break ;
	}
	if (*line == NULL)
		write(1, "An error occured", 16);
	if (eof == 0)
		return (0);
	return (1);
}
