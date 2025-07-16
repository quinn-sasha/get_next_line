/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:05:16 by squinn            #+#    #+#             */
/*   Updated: 2025/07/16 16:09:13 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

static void	*handle_error_or_end_of_file(char **prefix, char **buffer,
										ssize_t num_bytes)
{
	char	*temp;

	free(*buffer);
	if (num_bytes < 0)
	{
		if (*prefix)
			free(*prefix);
		return (NULL);
	}
	if (*prefix)
	{
		temp = *prefix;
		*prefix = NULL;
		return (temp);
	}
	return (NULL);
}

static void	join_prefix_and_buffer(char **prefix, char **buffer)
{
	char	*temp;

	if (!*prefix)
		*prefix = ft_strdup("");
	temp = *prefix;
	*prefix = ft_strjoin(temp, *buffer);
	free(temp);
	free(*buffer);
}

static void	set_new_prefix(char **prefix, int newline_pos)
{
	char	*temp;
	int		last;

	temp = *prefix;
	last = ft_strlen(*prefix) - 1;
	if (newline_pos == last)
		*prefix = NULL;
	else
		*prefix = ft_substr(*prefix, newline_pos + 1, last);
	free(temp);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	ssize_t		num_bytes;
	static char	*prefix;
	int			newline_pos;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (TRUE)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (handle_error_or_end_of_file(&prefix, &buffer, -1));
		ft_bzero(buffer, BUFFER_SIZE + 1);
		num_bytes = read(fd, buffer, BUFFER_SIZE);
		if (num_bytes < 0 || num_bytes == 0)
			return (handle_error_or_end_of_file(&prefix, &buffer, num_bytes));
		join_prefix_and_buffer(&prefix, &buffer);
		newline_pos = ft_strchr(prefix, '\n');
		if (newline_pos == NOT_FOUND)
			continue ;
		line = ft_substr(prefix, 0, newline_pos);
		set_new_prefix(&prefix, newline_pos);
		return (line);
	}
}
