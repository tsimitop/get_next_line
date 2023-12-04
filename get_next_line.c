/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:12:05 by tsimitop          #+#    #+#             */
/*   Updated: 2023/12/04 17:45:33 by tsimitop         ###   ########.fr       */
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
	while ((gnl_strchr(line_const, '\n') == 0) && chars_read > 0 && line_const)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
		chars_read = read(fd, buffer, BUFFER_SIZE);//-1 if error
		if (chars_read == -1)
			return (free(line_const), free(buffer), buffer = NULL, line_const = NULL, NULL);//, free(line_const),			!!!!!!!!!!!
		// buffer[BUFFER_SIZE] = '\0';
		// if (chars_read == 0)//check			epi to pleiston xeirotera, isos xreiazetai kai alla check
		// 	return (free(buffer), line_const);
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
	// while (--i >= 0)
	// 	buffer[i] = line_const[i];
	i = 0;
	while (line_const && line_const[i] != '\0' && line_const[i] != '\n')
	{
		buffer[i] = line_const[i];
		i++;
	}
	if (line_const[i] == '\n')
		buffer[i] = '\n';
	return (buffer);
}

char	*remaining_line(char *line_const)
{
	int		i;
	int		j;
	int		o;
	char	*remaining_chars;

	i = 0;
	j = 0;
	o = 0;
	if (!line_const)
		return (NULL);
	if (line_const[i] == '\0')
		return (free(line_const), line_const = NULL, NULL);//return (free(line_const), line_const = NULL, NULL);
	while (line_const && line_const[i] != '\n' && line_const[i] != '\0')
		i++;
	j = i;
	while (line_const && line_const[i] != '\0') // line_const[i] != '\n' &&
		i++;
	remaining_chars = ft_calloc((i + 1) - j, sizeof(char));
	if (!remaining_chars)
		return (free(line_const), NULL);
	if (line_const[i] != '\n')
		j++;
	while (line_const[j] != '\0') // read past alloc????
		remaining_chars[o++] = line_const[j++];
	return (free(line_const), line_const = NULL, remaining_chars);
}
// pointer after free set to NULL !!!!!!!!!!!!!!!!!!!!!!!!!!
char	*get_next_line(int fd)
{
	static char	*line_const = NULL;
	char		*current_line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0) //<0
		return (free(line_const),line_const = NULL, NULL);//line_const = NULL sets pointer to NULL
	if (line_const == NULL)
	{
		line_const = ft_calloc(1, sizeof(char));
		if (!line_const)
			return (NULL);
	}
	line_const = read_line(line_const, fd);
	if (!line_const)
		return (NULL);// return null
	current_line = return_line(line_const);
	// if (!current_line || current_line[i] == '\0')// || current_line == 0 //return null
	// 	return (NULL);		check entos functions
	line_const = remaining_line(line_const);
// dprintf(2, ">>%p<<", line_const);
	// if (!line_const)
	// 	return (NULL);
	return (current_line);
}

// _____________________________________________________________________________

// int	main(void)
// {
// 	int		fd;

// 	fd = open("text.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(2));
// 	// printf("%s", get_next_line(fd));
// 	close(fd);
// }

// int main(void)
// {
// 	int			fd;
// 	char		*line;
// 	static int	count;
// 	// char		*current_line;

// 	// current_line = "hello, \n how am I doing?";
// 	count = 0;
// 	fd = open("text.txt", O_RDONLY);
// 	// line = get_next_line(fd);
// 	// count++;
// 	// printf("[%d]: %s\n", count, line);
// 	line = NULL;
// 	// if (fd == -1)
// 	// {
// 	// 	printf("Error opening file");
// 	// 	return (1);
// 	// }
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break ;
// 		printf("[%d]:%s\n", count, line);
// 		count++;
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }