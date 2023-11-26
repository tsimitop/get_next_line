#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

// Allocates (with malloc(3)) and returns a newstring, which is the result 
// of the concatenationof ’s1’ and ’s2’.
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		ptr[j] = s2[i];
		j++;
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}

// The strchr() function locates the first occurrence of c (converted to a char)
// in the string pointed to by s.
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}

// The bzero() function writes n zeroed bytes to the string s.
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*uc;

	i = 0;
	uc = s;
	while (i < n)
	{
		uc[i] = 0;
		i++;
	}
}

// The calloc() function allocates memory and initializes all bits to zero.
void	*ft_calloc(size_t count, size_t size)
{
	int	*ptr;

	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}

// Allocates (with malloc(3)) and returns a substring from the string ’s’. The
// substring begins at index ’start’ and is of maximum size ’len’.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;
	size_t	len_create;
	size_t	len_s;

	i = 0;
	len_s = ft_strlen(s);
	// if (start >= len_s)
	// 	return (NULL); ///			ERROR DETAILS WHEN COMMENTED
	if (len_s - start < len)
		len_create = len_s - start;
	else
		len_create = len;
	cpy = (char *)malloc(len_create + 1);
	if (!cpy)
		return (NULL);
	while (s[start + i] != '\0' && i < len_create)
	{
		cpy[i] = s[start + i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
