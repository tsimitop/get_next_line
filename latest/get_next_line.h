/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:26:13 by tsimitop          #+#    #+#             */
/*   Updated: 2023/12/07 18:28:38 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
// char	*ft_strchr(const char *s, int c);
int		gnl_strchr(char *s, int c);
// void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

size_t	gnl_strlen( char *str);
char	*ft_strchr(char *s, int c);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif