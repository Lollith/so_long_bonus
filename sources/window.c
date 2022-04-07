/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:08:54 by agouet            #+#    #+#             */
/*   Updated: 2022/04/04 11:28:23 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	def_window_size(t_data *data)
{
	int	len;

	len = 0 ;
	while (data->map.map[len] != '\n')
		len ++;
	data->win.win_width = len * NB_PIXELS;
	data->win.win_height = (ft_strlen(data->map.cut_map)) / len * NB_PIXELS;
}

int	create_mlx(t_data *data)
{
	data->pt_mlx = mlx_init();
	if (data->pt_mlx == NULL)
	{
		free(data->pt_mlx);
		return (msg_perror("MLX"));
	}
	return (0);
}

int	create_window(t_data *data)
{
	def_window_size(data);
	data->pt_win = mlx_new_window(data->pt_mlx, data->win.win_width,
			data->win.win_height, "So_long");
	if (data->pt_win == NULL)
	{
		mlx_destroy_display(data->pt_mlx);
		mlx_destroy_window(data->pt_mlx, data->pt_win);
		free(data->pt_win);
		free(data->pt_mlx);
		return (msg_perror("Window"));
	}
	return (0);
}
