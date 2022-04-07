/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:17:05 by agouet            #+#    #+#             */
/*   Updated: 2022/04/05 10:48:47 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_map(t_data *data, int fd)
{
	char	*map;
	char	*line;

	map = NULL;
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			check_line(line, data);
		map = ft_strjoin(map, line);
		free(line);
	}
	if (map != NULL)
		return (map);
	else
	{
		free (map);
		return (NULL);
	}
}

int	count_line(t_data *data)
{
	int	len;

	len = 0;
	data->map.len_line = 0;
	while (data->map.map[len] != '\n')
		len++;
	data->map.len_line = len;
	return (len);
}

void	cut_map(t_data *data)
{
	char	*new_map;
	size_t	start;
	char	*last_map;

	start = 0;
	new_map = NULL;
	last_map = NULL;
	count_line(data);
	while (start < ft_strlen(data->map.map))
	{
		new_map = ft_substr(data->map.map, start, data->map.len_line);
		last_map = ft_strjoin(last_map, new_map);
		free(new_map);
		start = start + data->map.len_line + 1;
	}
	data->map.cut_map = ft_strdup(last_map);
	free(last_map);
}

int	create_map(t_data *data)
{
	int	fd;

	fd = open (data->map.ber, O_RDONLY);
	if (fd == -1)
		msg_perror("Open");
	data->map.map = get_map(data, fd);
	if (close(fd) == -1)
		msg_perror("Close");
	cut_map (data);
	return (0);
}
