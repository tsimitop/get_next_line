#include <stddef.h>
#include "get_next_line.h"
#include <stdio.h>

char	*read_line(char *line_progression, int fd)
{
	char	*buffer;
	int		chars_read;

	chars_read = 1;
	while ((ft_strchr(line_progression, '\n') == NULL)) //chars_read > 0 && 
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read <= 0)
			return (free(buffer), NULL);
		// *line_progression = *buffer;
		// line_progression++;
		// buffer++;
		line_progression = ft_strjoin(line_progression, buffer);
		free(buffer);
	}
	return (line_progression);
}

char	*return_line(char	*line_progression, int fd)
{
	char	*buffer;
	int		i;

	i = 0;
	while (line_progression && line_progression[i] != '\0' && line_progression[i] != '\n')
		i++;
	printf("thaleia\n");
	buffer = ft_calloc(i + 1, sizeof(char));			// na 3exwrisw cases
	if (!buffer)
		return (NULL);
	i = 0;
	while (line_progression && line_progression[i] != '\0' && line_progression[i] != '\n')
	{
		buffer[i] = line_progression[i];
		i++;
	}					// NA TSEKARO GIA OTAN DEN EXEI \n
	return (buffer);
}

char	*remaining_line(char *line_progression, int fd)
{
	int		i;
	int		j;
	char	*remaining_chars;

	i = 0;
	j = 0;
	if (!line_progression)
		return (NULL);
	while (line_progression && line_progression[i] != '\n')
	{
		j++;
		i++;
	}
	i++;
	while (line_progression && line_progression[i] != '\n' && line_progression[i] != 0)
		i++;
	remaining_chars = ft_calloc((i + 1) - j, sizeof(char));
	if (!remaining_chars)
		return (NULL);
	i = 0;
	while (j > 0)
	{
		remaining_chars[i] = line_progression[i];
		i++;
		j--;
	}
	return (remaining_chars);
}

char	*get_next_line(int fd)
{
	static char	*line_progression = NULL;
	char		*current_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_progression = ft_calloc(1, sizeof(char));
	line_progression = read_line(line_progression, fd);
	printf("test2\n");
	// if (!line_progression)
	// 	return (NULL);
	current_line = return_line(line_progression, fd);
	printf("hello\n");
	line_progression = remaining_line(line_progression, fd);
	return (current_line);
}

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
// 	// line = NULL;
// 	if (fd == -1)
// 	{
// 		printf("Error opening file");
// 		return (1);
// 	}
// 	while (1)
// 	{
// 		printf("test1\n");
// 		line = get_next_line(fd);
// 		printf("test3\n");
// 		if (line == NULL)
// 			break ;
// 		printf("[%d]:%s\n", count++, line);
// 		printf("test4\n");
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }

// _____________________________________________________________________________

// int	main(void)
// {
// 	int		fd;
// 	// char	*temp;

// 	fd = open("text.txt", O_RDONLY);
// 	printf("1;	%s	\n", get_next_line(fd));
// 	printf("2;	%s	\n", get_next_line(fd));
// 	printf("2;	%s	\n", get_next_line(fd));
// 	printf("2;	%s	\n", get_next_line(fd));
// 	printf("2;	%s	\n", get_next_line(fd));
// 	// if (BUFFER_SIZE > 100)
// 	// {
// 	// 	do {
// 	// 		temp = get_next_line(fd);
// 	// 	free(temp);
// 	// 	}
// 	// while (temp != NULL)
// 	// 	;
// 	// }
// 	// printf("3;	%s	", get_next_line(-1));
// 	close(fd);
// 	// fd = open("text.txt", O_RDONLY);
// }


// 	gia return_line
// 	if (line_progression[i] == '\n')
// 	{
// 		buffer = ft_calloc(i + 1, sizeof(char));
// 		i = 0;
// 		if (!buffer)
// 			return (NULL);
// 		while (line_progression[i] != '\n')
// 		{
// 			buffer[i] = line_progression[i];
// 			i++;
// 		}
// 		buffer[++i] = 0;
// 	}
// 	else if (line_progression[i] == 0)
// 	{
// 		i = 0;
// 		buffer = ft_calloc(i, sizeof(char));
// 		if (!buffer)
// 			return (NULL);
// 		while (line_progression[i] != 0)
// 		{
// 			buffer[i] = line_progression[i];
// 			i++;
// 		}
// 	}



// CHATGPT
// char *read_line(char *line_progression, int fd)
// {
//     char *buffer;
//     int chars_read;

//     chars_read = 1;
//     while (!(ft_strchr(line_progression, '\n') == NULL)) //chars_read > 0 &&
//     {
//         buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
//         if (!buffer)
//             return (NULL);
//         chars_read = read(fd, buffer, BUFFER_SIZE);
//         if (chars_read <= 0)
//         {
//             free(buffer);
//             return (NULL);
//         }

//         size_t len_line = ft_strlen(line_progression);
//         char *new_line_progression = ft_calloc(len_line + chars_read + 1, sizeof(char));
//         if (!new_line_progression)
//         {
//             free(buffer);
//             return (NULL);
//         }

//         // Copy contents of line_progression into new_line_progression
//         ft_memcpy(new_line_progression, line_progression, len_line);

//         // Copy contents of buffer into new_line_progression
//         ft_memcpy(new_line_progression + len_line, buffer, chars_read);

//         // Free original line_progression and buffer
//         free(line_progression);
//         free(buffer);

//         // Update line_progression to point to the new buffer
//         line_progression = new_line_progression;
//     }
//     return (line_progression);
// }