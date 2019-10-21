/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: douatla <douatla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 10:38:23 by djulian           #+#    #+#             */
/*   Updated: 2019/10/21 17:38:50 by douatla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*malloc_line(char **line, char *buffer)
{
	static int	current_line;
	int			line;
	int 		i;
	
	current_line = 0;
	line = 0;
	current_line++;
	i = 0;
	while (line <= current_line)
	{
		while(buffer[i] != '\n' || buffer[i] != '\0')
			i++;
	}
}