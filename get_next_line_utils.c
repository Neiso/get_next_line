/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djulian <djulian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:38:23 by djulian           #+#    #+#             */
/*   Updated: 2019/10/23 17:36:12 by djulian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"

// char	*find_line(char *buffer_file)
// {
// 	static int	line_to_be_read = 0;
// 	int			lines_counter;
// 	char		*line;
// 	int			i;

// 	lines_counter = 0;
// 	while (lines_counter < line_to_be_read)
// 		lines_counter = *buffer_file++ == '\n' ? ++lines_counter : lines_counter;
// 	line_to_be_read++;
// 	i = -1;
// 	while (buffer_file[++i] != '\n' && buffer_file[i] != '\0');
// 	if (!(line = malloc(i + 1)))
// 		return (NULL);
// 	i = -1;
// 	while(buffer_file[++i] != '\0' && buffer_file[i] != '\n')
// 		line[i] = buffer_file[i];
// 	line[i] = '\0';
// 	return (line);
// }
