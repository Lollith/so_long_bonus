/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:23:57 by agouet            #+#    #+#             */
/*   Updated: 2022/02/09 11:18:17 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/get_next_line.h"

int	ft_chr(const char *s, int c)
{
	if (!s)
		return (1);
	while (*s)
	{
		if ((char) *s == (char) c)
			return (0);
		s++;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char		*save_buf;
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	static char	*next;
	char		*save_line;

	save_line = NULL;
	if (fd < 0 || (read (fd, buf, 0) < 0) || BUFFER_SIZE < 0)
		return (NULL);
	while (ft_chr(save_line, '\n'))
	{
		buf[read (fd, buf, BUFFER_SIZE)] = '\0';
		if (!buf[0] && !next)
			return (save_line);
		save_buf = ft_strjoin(next, buf);
		next = ft_mstrchr(save_buf, '\n');
		line = ft_substr(save_buf, 0, (ft_strlen(save_buf) - ft_strlen(next)));
		free(save_buf);
		save_line = ft_strjoin(save_line, line);
		free(line);
	}
	return (save_line);
}	
