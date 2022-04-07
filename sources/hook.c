/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:03:19 by agouet            #+#    #+#             */
/*   Updated: 2022/04/04 13:15:44 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	esc_hook(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_loop_end(data->pt_mlx);
	return (0);
}

int	ft_close(t_data *data)
{
	mlx_loop_end(data->pt_mlx);
	return (0);
}

void	ft_key_loop_hook(t_data *data)
{
	mlx_hook(data->pt_win, 2, 1L << 0, keypress, data);
	mlx_key_hook(data->pt_win, esc_hook, data);
	mlx_hook(data->pt_win, 17, 0, ft_close, data);
}

int	keypress(int keysym, t_data *data)
{
	if (keysym == XK_w || keysym == XK_Up)
		move_up(data);
	if (keysym == XK_s || keysym == XK_Down)
		move_down(data);
	if (keysym == XK_a || keysym == XK_Left)
		move_left(data);
	if (keysym == XK_d || keysym == XK_Right)
		move_right(data);
	return (0);
}
