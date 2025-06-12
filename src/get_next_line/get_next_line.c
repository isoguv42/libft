/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igyuveni <igyuveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:24:21 by igyuveni          #+#    #+#             */
/*   Updated: 2024/12/20 22:09:34 by igyuveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static void	*gnl_free(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

static char	*extract_line(char **line, char *buf, int *found_nl)
{
	char	*new_line;
	char	*buf_part;
	size_t	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n' && ++i)
		*found_nl = 1;
	buf_part = ft_substr(buf, 0, i);
	if (!buf_part)
		return (gnl_free(line), NULL);
	if (!*line)
		new_line = buf_part;
	else
	{
		new_line = ft_strjoin(*line, buf_part);
		free(*line);
		free(buf_part);
		if (!new_line)
			return (gnl_free(line), NULL);
	}
	*line = new_line;
	ft_strlcpy(buf, buf + i, BUFFER_SIZE + 1);
	return (*line);
}

static char	*read_line(int fd, char *line, char *buf)
{
	int		found_nl;
	ssize_t	r;

	found_nl = 0;
	while (!found_nl)
	{
		if (!buf[0])
		{
			r = read(fd, buf, BUFFER_SIZE);
			if (r == -1)
				return (gnl_free(&line), ft_bzero(buf, BUFFER_SIZE + 1), NULL);
			if (r == 0)
				break ;
			buf[r] = '\0';
		}
		if (!extract_line(&line, buf, &found_nl))
			return (NULL);
	}
	if (!line || line[0] == '\0')
		return (gnl_free(&line), NULL);
	return (line);
}

/** Reads one line from file descriptor */
char	*get_next_line(int fd)
{
	static char	*buf[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	if (!buf[fd])
	{
		buf[fd] = malloc(BUFFER_SIZE + 1);
		if (!buf[fd])
			return (NULL);
		buf[fd][0] = '\0';
	}
	line = read_line(fd, NULL, buf[fd]);
	if (!line)
	{
		free(buf[fd]);
		buf[fd] = NULL;
	}
	return (line);
}
