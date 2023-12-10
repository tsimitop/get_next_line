#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;

	fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
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