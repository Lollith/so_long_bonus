/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:13:10 by agouet            #+#    #+#             */
/*   Updated: 2022/04/05 10:49:36 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.map.ber = "./maps/map1.ber";
	if (argc == 2)
		data.map.ber = argv[1];
	if (argc > 2)
	{
		msg_error("Too much arg\n");
		return (0);
	}
	create_map(&data);
	if (checks_map(&data))
		return (0);
	create_mlx(&data);
	create_window(&data);
	initialisation(&data);
	ft_key_loop_hook(&data);
	mlx_loop_hook(data.pt_mlx, &render_map, &data);
	mlx_loop(data.pt_mlx);
	mlx_destroy_window(data.pt_mlx, data.pt_win);
	ft_distroy_img(&data);
	mlx_destroy_display(data.pt_mlx);
	ft_free(&data);
	return (0);
}
