/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:12:05 by tsimitop          #+#    #+#             */
/*   Updated: 2023/12/10 17:37:40 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "get_next_line.h"
#include <stdio.h>

char	*read_line(char *line_const, int fd)
{
	char	*buffer;
	int		chars_read;

	chars_read = 1;
	while ((ft_strchr(line_const, '\n') == NULL) && chars_read > 0 && line_const)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
		chars_read = read(fd, buffer, BUFFER_SIZE);//-1 if error
		if (chars_read == -1)
			return (free(line_const), free(buffer), buffer = NULL, line_const = NULL, NULL);
		// if (chars_read == 0)
		// 	return (free(buffer), buffer = NULL, line_const);
		line_const = ft_strjoin(line_const, buffer);
		free(buffer);
	}
	return (line_const);
}

char	*return_line(char	*line_const)
{
	char	*buffer;// allagh onomatos
	int		i;

	i = 0;
	if (line_const[i] == '\0')
		return (NULL);
	while (line_const && line_const[i] != '\0' && line_const[i] != '\n')
		i++;
	if (line_const[i] == '\n')
		i++;
	buffer = ft_calloc(i + 1, sizeof(char));
	if (!buffer)
		return (free(line_const),line_const = NULL, NULL);//return (free(line_const),NULL);
	i = 0;
	while (line_const && line_const[i] != '\0' && line_const[i] != '\n')//ARIS && line_const[i] != '\n'
	{
		buffer[i] = line_const[i];
		i++;
	}
	if (line_const[i] == '\n')
		buffer[i] = '\n';
	return (buffer);
}

char *remaining_line(char *line_const)
{
	int i = 0;
	char *remaining_chars;
	char	*newline_startingpoint;

	if (!line_const)
		return (NULL);
	remaining_chars = 0;
	newline_startingpoint = ft_strchr(line_const, '\n');
	if (!newline_startingpoint)
		line_const[0] = '\0';
	else
	{
		while (line_const && line_const[i] != '\n')	// && line_const[i] != '\0'
			i++;
		line_const[i] = '\0';
		if (line_const + i + 1)
			remaining_chars = ft_strdup(line_const + i + 1);
	}
	
	// remaining_chars = 0;
	// if (ft_strchr(line_const, '\n') == NULL)	//DEN ALLAZEI KATI MALLON
	// 	return (free(line_const), line_const = NULL, NULL);
	return (free(line_const), line_const = NULL, remaining_chars);
}

char	*get_next_line(int fd)
{
	static char	*line_const = NULL;
	char		*current_line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0) //<0
		return (free(line_const), line_const = NULL, NULL);//line_const = NULL sets pointer to NULL
	if (line_const == NULL)
	{
		line_const = ft_calloc(1, sizeof(char));
		if (!line_const)
			return (NULL);
	}
	line_const = read_line(line_const, fd);
// printf("TEST\n");
	if (!line_const)
		return (NULL);
	current_line = return_line(line_const);
	if (!current_line)
		return (free(line_const), line_const = NULL, NULL);		//check entos functions
	line_const = remaining_line(line_const);
	// if (!line_const)
	// 	return (free(line_const), line_const = NULL, NULL);
// printf("WHERE?\n");
// printf("REMAINING LINE: %s", line_const);
	return (current_line);
}
