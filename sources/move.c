/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:47:06 by agouet            #+#    #+#             */
/*   Updated: 2022/04/07 11:28:48 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_data *data)
{
	data->direction.up = data->heroes.position - data->map.len_line;
	ft_move(data, &data->direction.up);
	return (0);
}

int	move_down(t_data *data)
{
	data->direction.down = data->heroes.position + data->map.len_line;
	ft_move(data, &data->direction.down);
	return (0);
}

int	move_left(t_data *data)
{
	data->direction.left = data->heroes.position - 1;
	data->heroes.state = LEFT;
	ft_move(data, &data->direction.left);
	return (0);
}

int	move_right(t_data *data)
{
	data->direction.right = data->heroes.position + 1;
	data->heroes.state = RIGHT;
	ft_move(data, &data->direction.right);
	return (0);
}

int	ft_move(t_data *data, int *direction)
{
	if (data->map.cut_map[*direction] == 'E' && data->e_xit.state == OPEN)
		ft_exit(data);
	else if (data->map.cut_map[*direction] != '1'
		&& data->map.cut_map[(*direction)] != 'E')
	{
		if (data->map.cut_map[*direction] == 'C')
			data->items.count --;
		data->map.cut_map[data->heroes.position] = '0';
		data->heroes.position = *direction;
		data->map.cut_map[data->heroes.position] = 'P';
		data->heroes.count++;
		write (1, "\rMovement Number: ", 17);
		ft_putnbr(data->heroes.count);
	}
	return (0);
}
