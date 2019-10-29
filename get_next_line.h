/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:44:55 by djulian           #+#    #+#             */
/*   Updated: 2019/10/29 09:02:17 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

int		get_next_line(int fd, char **line);
char	*line_break_in_buffer(char *buffer, char *line);
int		search_line_break (char *s);
int		ft_strlen(char *s);
char	*fill_line(char *buffer, char *line);

#endif
