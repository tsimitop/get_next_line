/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_the_beginning.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:12:46 by tsimitop          #+#    #+#             */
/*   Updated: 2023/12/03 18:12:50 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stddef.h>
// #include "get_next_line.h"
// #include <stdio.h>

// char	*read_line(char *line_progression, int fd)
// {
// 	char	*buffer;
// 	int		chars_read;

// 	chars_read = 1;
// 	while ((gnl_strchr(line_progression, '\n') == 0) && chars_read > 0 && line_progression) //chars_read > 0
// 	//  && \0 causes segfault			 && (gnl_strchr(line_progression, '\0')) == 0 separates each word
// 	{
// 		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
// 		if (!buffer)
// 			return (NULL);
// // printf("chars_read 0 = %d\n", chars_read);
// 		chars_read = read(fd, buffer, BUFFER_SIZE);
// printf("chars_read 1 = %d\n", chars_read);
// printf("BUFFER = %s\n", buffer);
// 		if (chars_read <= 0)
// 			return (free(buffer), NULL);
// // printf("chars_read 2 = %d\n", chars_read);
// 		line_progression = ft_strjoin(line_progression, buffer);
// printf("LINE PROGRESSION = %s\n", line_progression);
// 		free(buffer);
// // printf("read li\n");
// 	}
// 	return (line_progression);
// }

// char	*return_line(char	*line_progression)		//	, int fd
// {
// 	char	*buffer;
// 	int		i;

// 	i = 0;
// 	while (line_progression && line_progression[i] != '\0' && line_progression[i] != '\n')
// 		i++;
// // printf("thaleia\n");
// 	buffer = ft_calloc(i + 1, sizeof(char));			// na 3exwrisw cases
// 	if (!buffer)
// 		return (NULL);
// 	i = 0;
// 	while (line_progression && line_progression[i] != '\0' && line_progression[i] != '\n')
// 	{
// 		buffer[i] = line_progression[i];
// 		i++;
// 	}					// NA TSEKARO GIA OTAN DEN EXEI \n
// 	return (buffer);
// }

// char	*remaining_line(char *line_progression)		//	, int fd
// {
// 	int		i;
// 	int		j;
// 	char	*remaining_chars;

// 	i = 0;
// 	j = 0;
// printf("rem line1\n");
// 	if (!line_progression)
// 		return (NULL);
// printf("rem line2\n");
// 	while (line_progression && line_progression[i] != '\n' && line_progression[i] != '\0')
// 	{
// 		j++;
// 		i++;
// 	}
// // printf("rem line3\n");
// 	i++;	// what if null?
// 	// if (line_progression[i] == '\0')
// 	// 	return (NULL);
// // printf("rem line4\n");
// 	while (line_progression && line_progression[i] != '\n' && line_progression[i] != 0)
// 		i++;
// // printf("rem line5\n");
// 	remaining_chars = ft_calloc((i + 1) - j, sizeof(char));
// 	if (!remaining_chars)
// 		return (NULL);
// // printf("rem line6\n");
// 	i = 0;
// 	while (j > 0)
// 	{
// 		remaining_chars[i] = line_progression[i];
// 		i++;
// 		j--;
// 	}
// printf("REM LINE7\n");
// printf("REMAINING CHARS RVALUE: %s\n", remaining_chars);
// 	return (remaining_chars);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*line_progression = NULL;
// 	char		*current_line;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	line_progression = ft_calloc(1, sizeof(char));
// 	if (!line_progression)
// 		return (NULL);
// 	line_progression = read_line(line_progression, fd);
// // printf("gnl1\n");
// 	// if (!line_progression)
// 	// 	return (NULL);
// 	current_line = return_line(line_progression);		//	, int fd
// // printf("gnl2\n");
// 	line_progression = remaining_line(line_progression);		//	, int fd
// printf("gnl3\n");
// 	if (!line_progression)
// 		return (NULL);
// printf("gnl4\n");
// 	return (current_line);
// }


// // _____________________________________________________________________________

// int	main(void)
// {
// 	int		fd;

// 	fd = open("text.txt", O_RDONLY);
// 	printf("			1ST CALL OF GNL;	%s	\n\n\n\n", get_next_line(fd));
// 	printf("			2ND CALL OF GNL;	%s	\n\n\n\n", get_next_line(fd));
// 	printf("			3RD CALL OF GNL;	%s	\n\n\n\n", get_next_line(fd));
// 	printf("			4TH CALL OF GNL;	%s	\n\n\n\n", get_next_line(fd));
// 	// printf("5;	%s	\n", get_next_line(fd));
// 	close(fd);
// }

// // int main(void)
// // {
// // 	int			fd;
// // 	char		*line;
// // 	static int	count;
// // 	// char		*current_line;

// // 	// current_line = "hello, \n how am I doing?";
// // 	count = 0;
// // 	fd = open("text.txt", O_RDONLY);
// // 	// line = get_next_line(fd);
// // 	// count++;
// // 	// printf("[%d]: %s\n", count, line);
// // 	// line = NULL;
// // 	if (fd == -1)
// // 	{
// // 		printf("Error opening file");
// // 		return (1);
// // 	}
// // 	while (1)
// // 	{
// // 		printf("test1\n");
// // 		line = get_next_line(fd);
// // 		printf("test3\n");
// // 		if (line == NULL)
// // 			break ;
// // 		printf("[%d]:%s\n", count++, line);
// // 		printf("test4\n");
// // 		free(line);
// // 	}
// // 	close(fd);
// // 	return (0);
// // }

// // 	gia return_line
// // 	if (line_progression[i] == '\n')
// // 	{
// // 		buffer = ft_calloc(i + 1, sizeof(char));
// // 		i = 0;
// // 		if (!buffer)
// // 			return (NULL);
// // 		while (line_progression[i] != '\n')
// // 		{
// // 			buffer[i] = line_progression[i];
// // 			i++;
// // 		}
// // 		buffer[++i] = 0;
// // 	}
// // 	else if (line_progression[i] == 0)
// // 	{
// // 		i = 0;
// // 		buffer = ft_calloc(i, sizeof(char));
// // 		if (!buffer)
// // 			return (NULL);
// // 		while (line_progression[i] != 0)
// // 		{
// // 			buffer[i] = line_progression[i];
// // 			i++;
// // 		}
// // 	}



// // CHATGPT
// // char *read_line(char *line_progression, int fd)
// // {
// //     char *buffer;
// //     int chars_read;

// //     chars_read = 1;
// //     while (!(ft_strchr(line_progression, '\n') == NULL)) //chars_read > 0 &&
// //     {
// //         buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
// //         if (!buffer)
// //             return (NULL);
// //         chars_read = read(fd, buffer, BUFFER_SIZE);
// //         if (chars_read <= 0)
// //         {
// //             free(buffer);
// //             return (NULL);
// //         }

// //         size_t len_line = ft_strlen(line_progression);
// //         char *new_line_progression = ft_calloc(len_line + chars_read + 1, sizeof(char));
// //         if (!new_line_progression)
// //         {
// //             free(buffer);
// //             return (NULL);
// //         }

// //         // Copy contents of line_progression into new_line_progression
// //         ft_memcpy(new_line_progression, line_progression, len_line);

// //         // Copy contents of buffer into new_line_progression
// //         ft_memcpy(new_line_progression + len_line, buffer, chars_read);

// //         // Free original line_progression and buffer
// //         free(line_progression);
// //         free(buffer);

// //         // Update line_progression to point to the new buffer
// //         line_progression = new_line_progression;
// //     }
// //     return (line_progression);
// // }