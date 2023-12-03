#include <stddef.h>
#include "get_next_line.h"
#include <stdio.h>

char	*read_line(char *line_progression, int fd)
{
	char	*buffer;
	int		chars_read;

	chars_read = 1;
	while ((gnl_strchr(line_progression, '\n') == 0) && chars_read > 0 && line_progression)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read <= 0)
			return (free(buffer), line_progression);
		line_progression = ft_strjoin(line_progression, buffer);
		free(buffer);
	}
	return (line_progression);
}

char	*return_line(char	*line_progression)
{
	char	*buffer;
	int		i;

	i = 0;
	while (line_progression && line_progression[i] != '\0' && line_progression[i] != '\n')
		i++;
	buffer = ft_calloc(i + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	i = 0;
	while (line_progression && line_progression[i] != '\0' && line_progression[i] != '\n')
	{
		buffer[i] = line_progression[i];
		i++;
	}
	if (line_progression[i] == '\n')
		buffer[i] = '\n';
	return (buffer);
}

char	*remaining_line(char *line_progression)
{
	int		i;
	int		j;
	int		o;
	char	*remaining_chars;

	i = 0;
	j = 0;
	o = 0;
	if (!line_progression)
		return (NULL);
	while (line_progression && line_progression[i] != '\n' && line_progression[i] != '\0')
	{
		j++;
		i++;
	}
	while (line_progression && line_progression[i] != '\n' && line_progression[i] != 0)
		i++;
	remaining_chars = ft_calloc((i + 1) - j, sizeof(char));
	if (!remaining_chars)
		return (NULL);
	while (j > 0)
	{
		i++;
		remaining_chars[o] = line_progression[i];
		j--;
		o++;
	}
	return (remaining_chars);
}

char	*get_next_line(int fd)
{
	static char	*line_progression = NULL;
	char		*current_line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (line_progression == NULL)
	{
		line_progression = ft_calloc(1, sizeof(char));
		if (!line_progression)
			return (NULL);
	}
	line_progression = read_line(line_progression, fd);
	if (!line_progression)
		return (NULL);		// return null
	current_line = return_line(line_progression);
	if (!current_line || current_line[i] == '\0')	// || current_line == 0 //return null
		return (NULL);
	line_progression = remaining_line(line_progression);
	if (!line_progression)
		return (NULL);
	return (current_line);
}

// _____________________________________________________________________________

int	main(void)
{
	int		fd;

	fd = open("text.txt", O_RDONLY);
	// printf("%s", get_next_line(-1));
	// printf("%s", get_next_line(0));
	// printf("%s", get_next_line(1));
	// printf("%s", get_next_line(2));
	// printf("%s", get_next_line(fd));
	close(fd);
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
