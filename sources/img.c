/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:42:16 by agouet            #+#    #+#             */
/*   Updated: 2022/04/01 15:33:51 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	files_to_images(t_data *data)
{
	data->img.background = mlx_xpm_file_to_image(data->pt_mlx,
			BACKGROUND, &data->img.width, &data->img.height);
	data->img.wall = mlx_xpm_file_to_image(data->pt_mlx,
			WALL, &data->img.width, &data->img.height);
	data->img.heroes[RIGHT] = mlx_xpm_file_to_image(data->pt_mlx,
			HEROES, &data->heroes.width, &data->heroes.height);
	data->img.heroes[LEFT] = mlx_xpm_file_to_image(data->pt_mlx,
			HEROES_LEFT, &data->heroes.width, &data->heroes.height);
	data->img.items = mlx_xpm_file_to_image(data->pt_mlx,
			ITEMS, &data->items.width, &data->items.height);
	data->img.e_xit[CLOSE] = mlx_xpm_file_to_image(data->pt_mlx,
			EXIT, &data->e_xit.width, &data->e_xit.height);
	data->img.e_xit[OPEN] = mlx_xpm_file_to_image(data->pt_mlx,
			EXIT_OPEN, &data->e_xit.width, &data->e_xit.height);
	data->img.end_game = mlx_xpm_file_to_image(data->pt_mlx,
			END_GAME, &data->end_game.width, &data->end_game.height);
	if (check_img(data))
		return (msg_perror("Image"));
	return (SUCCESS);
}

int	check_img(t_data *data)
{
	if (data->img.background == NULL)
		return (IMG_ERROR);
	if (data->img.wall == NULL)
		return (IMG_ERROR);
	if (data->img.heroes[RIGHT] == NULL)
		return (IMG_ERROR);
	if (data->img.heroes[LEFT] == NULL)
		return (IMG_ERROR);
	if (data->img.items == NULL)
		return (IMG_ERROR);
	if (data->img.e_xit[CLOSE] == NULL)
		return (IMG_ERROR);
	if (data->img.e_xit[OPEN] == NULL)
		return (IMG_ERROR);
	if (data->img.end_game == NULL)
		return (IMG_ERROR);
	return (0);
}

void	ft_distroy_img(t_data *data)
{
	mlx_destroy_image(data->pt_mlx, data->img.background);
	mlx_destroy_image(data->pt_mlx, data->img.wall);
	mlx_destroy_image(data->pt_mlx, data->img.heroes[RIGHT]);
	mlx_destroy_image(data->pt_mlx, data->img.heroes[LEFT]);
	mlx_destroy_image(data->pt_mlx, data->img.items);
	mlx_destroy_image(data->pt_mlx, data->img.e_xit[CLOSE]);
	mlx_destroy_image(data->pt_mlx, data->img.e_xit[OPEN]);
	mlx_destroy_image(data->pt_mlx, data->img.end_game);
}	
