# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: douatla <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 11:44:44 by douatla           #+#    #+#              #
#    Updated: 2020/03/04 14:29:45 by douatla          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Werror -Wextra

FILES = get_next_line.c get_next_line_utils.c 

GET_NEXT_LINE = get_next_line

LIBFT = ../libft.a

INCLUDE = get_next_line.h

FILES_O = $(FILES:.c=.o)

YELLOW = \033[0;33m

NO_COLOR = \033[0m

all : ${FILES_O} ${GET_NEXT_LINE}

${GET_NEXT_LINE} : ${FILES_O}
	@python3 -c 'print("${YELLOW}Get_next_line compiled with success.${NO_COLOR}")'
	@ar -rcs ${LIBFT} ${FILES_O}

clean : 
	@rm -rf ${FILES_O}

%.o: %.c ${INCLUDE}
	@${CC} ${FLAG} -c -o $@ $< 
	
