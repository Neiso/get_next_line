/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:38:23 by douatla           #+#    #+#             */
/*   Updated: 2019/10/28 08:45:33 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_concat(char *dest, char *src)
{
	char	*final_string;
	int		i;
	int		j;

	if (src == NULL)
		return(dest);
	i = -1;
	while (dest[++i] && dest != NULL);
	if(!(final_string = (char*)malloc(i + BUFFER_SIZE + 1)))
		return (NULL);
	i = -1;
	while (dest[++i] && dest != NULL)
		final_string[i] = dest[i];
	j = -1;
	i--;
	while (src[++j])
		final_string[++i] = src[j];
	final_string[++i] = '\0';
	return (final_string);
}

char	*get_all_line(int fd, char *tab)
{
	char	*buffer[BUFFER_SIZE + 1];
	char	*all_line;
	int		eof;

	eof = 0;
	all_line = NULL;
	while(eof != -1)
	{
		eof = read(fd, buffer, BUFFER_SIZE);
		if (eof != 0)
			buffer[eof] = '\0';
		while(ft_concat(all_line, buffer) != NULL);
	}
}

char	*find_line(char *buffer_file)
{
	static int	line_to_be_read = 0;
	int			lines_counter;
	char		*line;
	int			i;

	lines_counter = 0;
	i = -1;
	while ((lines_counter < line_to_be_read) && ++i < BUFFER_SIZE)
		lines_counter = *buffer_file++ == '\n' ? ++lines_counter : lines_counter;
	line_to_be_read++;
	i = -1;
	while (buffer_file[++i] != '\n' && buffer_file[i] != '\0');
	if (!(line = malloc(i + 1)))
		return (NULL);
	i = -1;
	while(buffer_file[++i] != '\0' && buffer_file[i] != '\n')
		line[i] = buffer_file[i];
	line[i] = '\0';
	return (line);
}
