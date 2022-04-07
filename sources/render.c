/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:14:24 by agouet            #+#    #+#             */
/*   Updated: 2022/04/05 11:52:55 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_fix_image_ini(t_data *data, int *pt_i)
{
	int	len;

	len = count_line(data);
	if (data->map.cut_map[*pt_i] == '1')
		mlx_put_image_to_window(data->pt_mlx, data->pt_win, data->img.wall,
			(*pt_i % len) * data->img.width, (*pt_i / len) * data->img.height);
	if (data->map.cut_map[*pt_i] == '0')
		mlx_put_image_to_window(data->pt_mlx, data->pt_win,
			data->img.background, (*pt_i % len) * data->img.width,
			(*pt_i / len) * data->img.height);
	if (data->map.cut_map[*pt_i] == 'C')
		mlx_put_image_to_window(data->pt_mlx, data->pt_win, data->img.items,
			(*pt_i % len) * data->items.width,
			(*pt_i / len) * data->items.height);
}

void	put_image_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.cut_map[i])
	{
		if (data->end_game.state == 0)
			put_fix_image_ini(data, &i);
		else
		{
			if (data->map.cut_map[i] == 'X')
				mlx_put_image_to_window(data->pt_mlx, data->pt_win,
					data->img.end_game, (data->win.win_width - 200) / 2,
					(data->win.win_height - 200) / 2);
		}
		i ++;
	}
}
