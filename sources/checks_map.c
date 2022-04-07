/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:18:33 by agouet            #+#    #+#             */
/*   Updated: 2022/04/05 10:49:10 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line(char *line, t_data *data)
{
	int	len;

	data->map.check_line = 0;
	len = 0;
	while (line[len] != '\n')
		len ++;
	if (len && data->map.check_line && data->map.check_line != len)
	{
		msg_error("Map is not rectangular.\n");
		exit(EXIT_FAILURE);
	}
	data->map.check_line = len;
	return (0);
}

int	checks_map(t_data *data)
{
	if (check_position(data))
		return (msg_error("Add one E, one P and at least one C on the map.\n"));
	if (check_wall1(data))
		return (msg_error("Walls.\n"));
	if (check_walls (data))
		return (msg_error("Walls.\n"));
	return (0);
}

int	check_position(t_data *data)
{
	char	*s;

	if (ft_strchr(data->map.map, 'C'))
	{	
		if (ft_strchr(data->map.map, 'E'))
		{
			if (ft_strchr(data->map.map, 'P'))
			{
				s = ft_strchr(data->map.map, 'P');
				if (ft_strchr((char *)(s + 1), 'P'))
					return (FAILURE);
				return (SUCCESS);
			}
		}
	}
	return (FAILURE);
}

int	check_wall1(t_data *data)
{
	int	i;
	int	len1;

	len1 = 1;
	i = 1;
	while (len1 < data->map.len_line)
	{
		if (data->map.cut_map[i * len1] != '1')
			return (FAILURE);
		len1 ++;
	}
	if (data->map.cut_map[(i * len1)] != '1')
		return (FAILURE);
	data->map.len1 = len1;
	return (SUCCESS);
}

int	check_walls(t_data *data)
{
	int	i;
	int	j;
	int	nb_line;

	nb_line = ft_strlen(data->map.cut_map) / data->map.len_line;
	i = 2;
	while (i < nb_line)
	{
		if (data->map.cut_map[(i * data->map.len1) - 1] != '1')
			return (FAILURE);
		if (data->map.cut_map[(i * data->map.len1)] != '1')
			return (FAILURE);
		i++;
	}
	i--;
	j = 0;
	while (j < data->map.len1)
	{
		if (data->map.cut_map[(i * data->map.len1) + j] != '1')
			return (FAILURE);
		j++;
	}
	return (SUCCESS);
}
