/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:40:12 by squinn            #+#    #+#             */
/*   Updated: 2025/07/15 18:04:39 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 4096
# define TRUE 1
# define NOT_FOUND -1

void		ft_bzero(void *s, size_t n);
static void	*handle_error_or_end_of_file(char *prefix, ssize_t num_bytes);
static void	join_prefix_and_buffer(char *prefix, char *buffer);
static void	set_new_prefix(char *prefix, int newline_pos);
char		*get_next_line(int fd);

int			ft_strlen(const char *s);
int			ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, int start, int last);

#endif
