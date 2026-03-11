/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 02:19:22 by vzurera-          #+#    #+#             */
/*   Updated: 2026/03/11 19:24:50 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUFF	4096

static char	*extract_line(char *line, char *newline, char *buffer)
{
	char	*tmp;
	int		len;
	int		blen;

	len = 0;
	if (line)
		len = ft_strlen(line);
	blen = newline - buffer;
	tmp = malloc(len + blen + 2);
	if (!tmp)
	{
		free(line);
		return (NULL);
	}
	if (line)
		ft_memcpy(tmp, line, len);
	ft_memcpy(tmp + len, buffer, blen);
	tmp[len + blen] = '\n';
	tmp[len + blen + 1] = '\0';
	ft_memmove(buffer, newline + 1, ft_strlen(newline + 1) + 1);
	free(line);
	return (tmp);
}

static char	*fill_line(char *line, char *buffer)
{
	char	*tmp;
	int		len;
	int		blen;

	len = 0;
	if (line)
		len = ft_strlen(line);
	blen = ft_strlen(buffer);
	tmp = malloc(len + blen + 1);
	if (!tmp)
	{
		free(line);
		return (NULL);
	}
	if (line)
		ft_memcpy(tmp, line, len);
	ft_memcpy(tmp + len, buffer, blen + 1);
	ft_memset(buffer, 0, BUFF + 1);
	free(line);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	buffer[1024][BUFF + 1];
	char		*line;
	char		*newline;
	int			bytes;

	line = NULL;
	if (fd < 0 || fd >= 1024 || BUFF <= 0)
		return (ft_memset(buffer[fd], 0, BUFF + 1), NULL);
	while (1)
	{
		if (!buffer[fd][0])
		{
			bytes = read(fd, buffer[fd], BUFF);
			if (bytes == 0)
				return (line);
			if (bytes < 0)
				return (ft_memset(buffer[fd], 0, BUFF + 1), free(line), NULL);
		}
		newline = ft_strchr(buffer[fd], '\n');
		if (newline)
			return (extract_line(line, newline, buffer[fd]));
		line = fill_line(line, buffer[fd]);
		if (!line)
			return (NULL);
	}
}
