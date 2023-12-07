/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:12:25 by tsimitop          #+#    #+#             */
/*   Updated: 2023/12/07 19:03:20 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	// if (!str)
	// 	return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
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

// Allocates (with malloc(3)) and returns a newstring, which is the result 
// of the concatenationof ’s1’ and ’s2’.
char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
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
	free(s1);
	return (ptr);
}


// The bzero() function writes n zeroed bytes to the string s.
static void	ft_bzero(void *s, size_t n)
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


// The strdup() function allocates sufficient memory for a copy of the string
// s1, does the copy, and returns a pointer to it.
char	*ft_strdup(char *s1)
{
	char	*ptr;
	size_t	i;
	size_t	len_s1cpy;

	if (!s1)
		return (NULL);
	len_s1cpy = ft_strlen(s1);
	i = 0;
	ptr = (char *)malloc(len_s1cpy + 1);
	if (!ptr)
		return (NULL);
	if (ptr)
	{
		while (len_s1cpy > i)
		{
			ptr[i] = s1[i];
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}

// Allocates (with malloc(3)) and returns a substring from the string ’s’. The
// substring begins at index ’start’ and is of maximum size ’len’.
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;
	size_t	len_create;
	size_t	len_s;

	i = 0;
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
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
