/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:50:34 by agouet            #+#    #+#             */
/*   Updated: 2022/04/05 11:51:38 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animation(t_data *data)
{
	int	i;
	int	len;

	len = count_line(data);
	i = 0;
	while (data->map.cut_map[i])
	{
		if (data->end_game.state == 0)
		{
			if (data->map.cut_map[i] == 'P')
				heroes_position(data, &i);
			if (data->map.cut_map[i] == 'E')
				exit_anim(data, &i);
		}
		else
		{
			if (data->map.cut_map[i] == 'P')
				mlx_put_image_to_window(data->pt_mlx, data->pt_win,
					data->img.background, (i % len) * data->img.width,
					(i / len) * data->img.height);
			if (data->map.cut_map[i] == 'E')
				exit_anim(data, &i);
		}
		i++;
	}
}

void	exit_anim(t_data *data, int *pt_i)
{
	int	len;

	len = count_line(data);
	mlx_put_image_to_window(data->pt_mlx, data->pt_win,
		data->img.e_xit[data->e_xit.state],
		(*pt_i % len) * data->img.width, (*pt_i / len) * data->img.height);
}

void	heroes_position(t_data *data, int *pt_i)
{
	int	i;

	i = *pt_i;
	data->heroes.position = i;
	data->heroes.x = (i % data->map.len_line) * data->img.width;
	data->heroes.y = (i / data->map.len_line) * data->img.height ;
	mlx_put_image_to_window(data->pt_mlx, data->pt_win,
		data->img.heroes[data->heroes.state],
		(data->heroes.x), (data->heroes.y));
}
