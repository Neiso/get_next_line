/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djulian <djulian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:43:16 by douatla           #+#    #+#             */
/*   Updated: 2019/10/25 10:40:32 by djulian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		search_line_break (char *s)
{
	int i;
	int booleen;

	booleen = 0;
	i = -1;
	if (s == NULL)
		return (0);
	while(s[++i])
	{
		if (s[i] == '\n')
		{
			booleen++;
			break ;
		}
	}
	if (booleen && s[++i] != '\0')
		return (2);
	if(booleen)
		return (1);
	return (0);
}

int		ft_strlen(char *s)
{
	int i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*find_line_break(char *buffer, char *line)
{
	char	*line_cpy;
	int		i;
	int		j;

	if (buffer[0] == '\n')
		return(line);
	if (!(line_cpy = (char*)malloc(ft_strlen(line) + 1)))
		return (NULL);
	i = -1;
	while (line != NULL && line[++i])
		line_cpy[i] = line[i];
	i = (i == -1 ? 0 : i);
	line_cpy[i] = '\0';
	i = -1;
	free(line);
	if (!(line = (char*)malloc(ft_strlen(buffer) + ft_strlen(line_cpy) + 1)))
		return (NULL);
	while (line_cpy[++i])
		line[i] = line_cpy[i];
	j = -1;
	i--;
	while (buffer[++j])
		line[++i] = buffer[j];
	line[++i] = '\0';
	return (line);
}

int		get_next_line(int fd, char **line)
{
	int				eof;
	static char		buffer[BUFFER_SIZE + 1];

	buffer[0] = '\0';
	if (search_line_break(buffer))
	*line = NULL;
	eof = -1;
	while (eof != 0)
	{
		eof = read(fd, buffer, BUFFER_SIZE);
		buffer[eof] = '\0';
		*line = find_line_break(buffer, *line);
		if (search_line_break(*line))
			break ;
		printf("line = %s\n", *line);
	}
	if (eof == 0)
		free(*line);
	return (1);
}

int main(int argc, char **argv)
{
	(void)argc;
	char *line;
	int fd;

	line = NULL;
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	printf("line final : %s", line);
	get_next_line(fd, &line);
	printf("line final :%s", line);
	get_next_line(fd, &line);
	printf("line final :%s", line);
	return (0);
}