/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:03:09 by agouet            #+#    #+#             */
/*   Updated: 2022/04/05 11:47:25 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_items_ini(t_data *data)
{
	int	i;

	i = 0;
	data->items.count = 0 ;
	while (data->map.cut_map[i])
	{
		if (data->map.cut_map[i] == 'C')
			data->items.count ++;
		i++;
	}
}

void	initialisation(t_data *data)
{
	data->map.check_line = 0;
	data->end_game.state = 0;
	count_items_ini(data);
	data->heroes.state = RIGHT;
	data->e_xit.state = CLOSE;
	data->heroes.count = 0;
	files_to_images(data);
}

int	render_map(t_data *data)
{
	put_image_map(data);
	animation(data);
	if (data->items.count == 0)
		data->e_xit.state = OPEN;
	return (0);
}

int	ft_exit(t_data *data)
{
	data->items.count = -1;
	data->e_xit.state = CLOSE;
	data->end_game.state = 1;
	data->map.cut_map[100] = 'X';
	return (0);
}
