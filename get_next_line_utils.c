/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:38:23 by djulian           #+#    #+#             */
/*   Updated: 2019/11/14 15:24:01 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**	after the first call of the function, if a line break is found in the buffer
**	from a last call there is two cases scenarios :
**		-Either the line break (\n) is the last character of the buffer, means
**		we dont need dont need to care, there are no characters from the new
**		line in the previous buffer so we cant clear the buffer and break the
**		function call
**		-Either there are charachters from the new line in the buffer so it
**		means we have to copy all the characters in the new line till the end
**		of the buffer OR a new line break and clear what we just copyed.
**	If there are still line break in the buffer, there wont be any READ call
**	because to enter the loop containing the READ function, the buffer
**	has to pass a test which determinate if there are still line break in the
**	buffer.
*/

char	*line_break_in_buffer(char *buffer, char *line)
{
	int		i;
	int		tmp;

	i = -1;
	while (buffer[++i] != '\n')
		buffer[i] = '0';
	buffer[i] = '0';
	if (buffer[++i] == '\0')
	{
		buffer[--i] = '0';
		return (NULL);
	}
	tmp = i - 1;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (!(line = (char*)malloc(i - tmp + 2)))
		return (NULL);
	i = -1;
	while (buffer[++tmp] != '\n' && buffer[tmp] != '\0')
		line[++i] = buffer[tmp];
	line[++i] = '\0';
	return (line);
}

/*
**	Search for line break in the buffer :
**		- Return 0 if it didn,t find any.
**		- Return the number of line break found.
**	This function is use two times :
**		- In the very first function call, it allows the WHILE loop to know when
**		to get out. Because if a line break is found in the buffer it means we
**		just reached the end of the first line. And if the buffer is clean, it
**		will enter the WHILE loop and fill up the buffer. Same case as the first
**		time call.
**		- In further calls, it is a booleen conditions to know if the function
**		should enter the loop or not. If there are still line break in the
**		buffer from a previous call, it means the buffer has to be cleared out
**		before any READ call.
*/

int		search_line_break(char *s)
{
	int i;
	int booleen;

	booleen = 0;
	i = -1;
	if (s == NULL)
		return (1);
	while (s[++i])
	{
		if (s[i] == '\n')
			booleen++;
	}
	return (booleen);
}

/*
**	dumb function to get the size of both the buffer and the line_cpy
**	so the malloc for line is done properly
*/

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

/*
**	This function is used only if the buffer is clean and so can enter the
**	WHILE loop where it gets fill up by a READ call. It will write the
**	line into the input LINE till it encounters a line break.
*/

char	*fill_line(char *buffer, char *line)
{
	char	*line_cpy;
	int		i;
	int		j;

	if (!(line_cpy = (char*)malloc(ft_strlen(line) + 1)))
		return (NULL);
	i = -1;
	while (line != NULL && line[++i])
		line_cpy[i] = line[i];
	i = (i == -1 ? 0 : i);
	line_cpy[i] = '\0';
	i = -1;
	if (!(line = (char*)malloc(ft_strlen(buffer) + ft_strlen(line_cpy) + 1)))
		return (NULL);
	while (line_cpy[++i])
		line[i] = line_cpy[i];
	free(line_cpy);
	j = -1;
	i--;
	while (buffer[++j] && buffer[j] != '\n')
		line[++i] = buffer[j];
	line[++i] = '\0';
	return (line);
}
