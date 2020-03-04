/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:22:01 by douatla           #+#    #+#             */
/*   Updated: 2020/03/04 14:21:13 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int				eof;
	static char		buffer[OPEN_MAX][BUFFER_SIZE + 1] = {{0}};

	if (line == NULL || fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (-1);
	*line = NULL;
	if (search_lb(buffer[fd]) && (*line = lb_buf(buffer[fd], *line)) == NULL)
		return (-1);
	eof = -1;
	while (eof != 0 && !(search_lb(buffer[fd])))
	{
		eof = read(fd, buffer[fd], BUFFER_SIZE);
		if (eof == -1)
			return (-1);
		buffer[fd][eof] = '\0';
		if ((*line = fill_line(buffer[fd], *line)) == NULL)
			return (-1);
		if (search_lb(buffer[fd]))
			break ;
	}
	if (eof == 0)
		return (0);
	return (1);
}
