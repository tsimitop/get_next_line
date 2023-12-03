// #include <stddef.h>
// #include "get_next_line.h"
// #include <stdio.h>

// char	*read_line(int fd, char *line_progression)
// {
// 	int		read_chars;
// 	char	*buffer;
// 	char	*temp;

// 	read_chars = 1;
// 	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
// 	if (!buffer)
// 		return (NULL);
// 	if (line_progression == NULL) //
// 	{
// // printf("line_progression: %s\n", line_progression);
// 		line_progression = ft_calloc(1, sizeof(char)); //////////////////
// // printf("line_progression 2: %s\n", line_progression);
// 	}
// 		if (!line_progression)
// 			return (NULL);
// 	while (!ft_strchr(line_progression, '\n') && read_chars > 0)
// 	{
// 		read_chars = read(fd, buffer, BUFFER_SIZE);//
// 		if (read_chars < 0)
// 		{
// 			free(buffer);
// 			return (NULL);
// 		}
// 		temp = line_progression;
// 		line_progression = ft_strjoin(temp, buffer); ///////////
// 		free(temp);
// // printf("line_progression 3: %s\n", line_progression);
// 	}
// 	free(buffer);
// 	return (line_progression);
// }

// char	*create_final(char **line_progression)
// {
// 	int		size;
// 	char	*final;
// 	char	*ptr;

// 	ptr = *line_progression;
// 	size = ft_strchr(*line_progression, '\n') - ptr + 1;
// 	final = ft_substr(ptr, 0, size);
// 	*line_progression = ft_substr(ptr, size, ft_strlen(ptr) - size + 1);
// 	free(ptr);
// 	return (final);
// }


// char	*get_next_line(int fd)
// {
// 	static char *line_progression;
// 	char		*current_line;
// 	// int			reading_position;

// 	current_line = 0;
// 	// reading_position = 0;
// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	line_progression = read_line(fd, line_progression);
// 	if (line_progression && *line_progression != 0)
// 		current_line = create_final(&line_progression);
// 	// reading_position += ft_strlen(current_line);
// 	return (current_line);
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
// // 		line = get_next_line(fd);
// // 		if (line == NULL)
// // 			break ;
// // 		printf("[%d]:%s\n", count, line);
// // 		line = NULL;
// // 	}
// // 	close(fd);
// // 	return (0);
// // }

// int	main(void)
// {
// 	int		fd;
// 	// char	*temp;

// 	fd = open("text.txt", O_RDONLY);
// 	printf("1;	%s	\n", get_next_line(fd));
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
