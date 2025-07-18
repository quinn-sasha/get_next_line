/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:05:09 by squinn            #+#    #+#             */
/*   Updated: 2025/07/18 09:16:34 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == (char)c)
		return (i);
	return (-1);
}

char	*ft_strdup(const char *s)
{
	char	*new_string;
	int		i;

	new_string = malloc(ft_strlen(s) + 1);
	if (!new_string)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_string[i] = s[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	i;
	size_t	j;

	new_string = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_string)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		new_string[i++] = s1[j++];
	j = 0;
	while (s2[j])
		new_string[i++] = s2[j++];
	new_string[i] = '\0';
	return (new_string);
}

char	*ft_substr(char const *s, int start, int last)
{
	int		src_len;
	char	*new_string;
	int		i;

	src_len = ft_strlen(s);
	if (start >= src_len)
		return (ft_strdup(""));
	if (start > last)
		return (ft_strdup(""));
	new_string = malloc(last - start + 2);
	if (!new_string)
		return (NULL);
	i = 0;
	while (i + start <= last)
	{
		new_string[i] = s[i + start];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
