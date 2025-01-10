/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbailuk <dbailuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:05:02 by dbailuk           #+#    #+#             */
/*   Updated: 2024/12/23 15:44:48 by dbailuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

static char	*ft_read_before_newline(int fd, char *storage)
{
	char	*buf;
	ssize_t	br;

	if (!storage)
		storage = ft_calloc(1, 1);
	if (!storage)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(storage), NULL);
	br = 1;
	while (!ft_strchr(storage, '\n') && br > 0)
	{
		br = read(fd, buf, BUFFER_SIZE);
		if (br == -1)
			return (free(buf), free(storage), NULL);
		buf[br] = '\0';
		storage = ft_strjoin(storage, buf);
		if (!storage)
			return (free(buf), NULL);
	}
	return (free(buf), storage);
}

static char	*ft_extract_line(char *storage)
{
	size_t	i;
	char	*line;

	if (!storage || !*storage)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		i++;
	line = ft_substr(storage, 0, i);
	return (line);
}

static char	*ft_update_storage(char *storage)
{
	size_t	i;
	char	*new_st;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
		return (free(storage), NULL);
	new_st = ft_strdup(storage + i + 1);
	free(storage);
	if (!new_st)
		return (NULL);
	return (new_st);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = ft_read_before_newline(fd, storage);
	if (!storage)
		return (NULL);
	line = ft_extract_line(storage);
	storage = ft_update_storage(storage);
	return (line);
}
