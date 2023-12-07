/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:12:05 by tsimitop          #+#    #+#             */
/*   Updated: 2023/12/07 18:24:36 by tsimitop         ###   ########.fr       */
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
			return (free(line_const), free(buffer), buffer = NULL, line_const = NULL, NULL);//, free(line_const),			!!!!!!!!!!!
		// buffer[BUFFER_SIZE] = '\0';
		// if (chars_read == 0)//check			epi to pleiston xeirotera, isos xreiazetai kai alla check
		// 	break ;
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

// char	*remaining_line(char *line_const)
// {
// 	int		i;
// 	int		j;
// 	int		o;
// 	char	*remaining_chars;

// 	i = 0;
// 	j = 0;
// 	o = 0;
// 	if (!line_const)
// 		return (NULL);
// 	if (line_const[i] == '\0')
// 		return (free(line_const), line_const = NULL, NULL);//return (free(line_const), line_const = NULL, NULL);
// 	while (line_const && line_const[i] != '\n' && line_const[i] != '\0')
// 		i++;
// 	j = i;
// 	while (line_const && line_const[i] != '\0') // line_const[i] != '\n' &&
// 		i++;
// 	remaining_chars = ft_calloc((i + 1) - j, sizeof(char));
// 	if (!remaining_chars)
// 		return (free(line_const), NULL);
// 	if (line_const[i] != '\n')
// 		j++;
// 	if (line_const[j] == '\0')	// && ft_strlen(line_const)> 0 //HEAP BUFFER OVERFLOW
// 		return (free(line_const), free(remaining_chars), remaining_chars = NULL, line_const = NULL, NULL);
// 	while (line_const && line_const[j] != '\0') // read past alloc????
// 	{
// 		remaining_chars[o++] = line_const[j++];
// // printf("REMAINING CHARS: %s", remaining_chars);
// 	}
// 	return (free(line_const), line_const = NULL, remaining_chars);
// }
// pointer after free set to NULL !!!!!!!!!!!!!!!!!!!!!!!!!!

// char	*remaining_line(char *line_const)
// {
// 	char	*remaining_chars;
// 	char		*ptr1;
// 	char		*ptr2;
// 	size_t	remaining_length;

// 	ptr1 = (ft_strchr(line_const, '\n'));
// 	ptr2 = (ft_strchr(line_const, '\0'));
// 	// if (ptr == NULL)
// 	// 	return (free(line_const), line_const = NULL, NULL);
// 	remaining_length = ft_strlen(*ptr2 - *ptr1);

// 	if (ft_strlen(ft_strchr(line_const, '\n') - &line_const) == 0)
// 		return (free(line_const), line_const = NULL, NULL);
// 	else
// 	{
// 		remaining_chars = ft_calloc((remaining_length), sizeof(char));
// 		if (!remaining_chars)
// 			return (free(line_const), line_const = NULL, NULL);
// 		while (1)
// 		{
// 			*remaining_chars++ = *ptr1++;
// 			if (*ptr1 == '\0')
// 				break;
// 		}
// 		return (free(line_const), line_const = NULL, remaining_chars);
// 	}
// }

// char	*remaining_line(char *line_const)
// {
// 	char	*temp;
// 	int		i;

// 	i = 0;
// 	temp = line_const;
// 	while (temp != '\n' && temp != '\0')
// 	{
// 		temp[i] = '\0';
// 	}
	
// }

// char	*remaining_line(char *line_const)
// {
// 	char	*temp;
// 	int		i;

// 	i = 0;
// 	temp = line_const;
// 	while (temp[i] != '\n' && temp[i] != '\0')
// 	{
// 		temp[i] = '\0';
// 		*temp = *temp++;
// 	}
// 	return (free(line_const), line_const = NULL, temp);
// }

char *remaining_line(char *line_const)
{
	int i = 0;

	if (!line_const)
		return (NULL);
	// Find the position of '\n' or '\0'
	while (line_const && line_const[i] != '\n' && line_const[i] != '\0')
		i++;
	// Null-terminate the string at the first occurrence of '\n' or '\0'
	line_const[i] = '\0';	
	// Allocate memory for the remaining characters
	char *remaining_chars = ft_strdup(line_const + i + 1);	
	// Free the memory at the beginning of line_const
	// free(line_const);	
	// Return a pointer to the newly allocated remaining characters
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
	if (!line_const)
		return (NULL);
	current_line = return_line(line_const);
	if (!current_line)
		return (free(line_const), line_const = NULL, NULL);		//check entos functions
	line_const = remaining_line(line_const);
// printf("REMAINING LINE: %s", line_const);
	return (current_line);
}
