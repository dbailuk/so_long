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

#include "includes/get_next_line.h"

static char	*ft_read_before_newline(int fd, char *storage)
{
	ssize_t	bytes_read;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(storage, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(storage);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	return (storage);
}

static char	*ft_extract_line(char *storage)
{
	size_t	len;
	char	*line;

	if (!storage || !*storage)
	{
		return (NULL);
	}
	len = 0;
	while (storage[len] && storage[len] != '\n')
		len++;
	if (storage[len] == '\n')
		len++;
	line = ft_substr(storage, 0, len);
	return (line);
}

static char	*ft_update_storage(char *storage)
{
	char	*new_storage;
	size_t	len;

	len = 0;
	while (storage[len] && storage[len] != '\n')
		len++;
	if (!storage[len])
	{
		free(storage);
		return (NULL);
	}
	new_storage = ft_strdup(storage + len + 1);
	free (storage);
	if (!new_storage)
	{
		return (NULL);
	}
	return (new_storage);
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
