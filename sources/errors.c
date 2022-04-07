/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:55:27 by agouet            #+#    #+#             */
/*   Updated: 2022/04/05 10:48:01 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	msg_error(char *error)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, error, ft_strlen (error));
	return (FAILURE);
}

int	msg_perror(char *origin)
{
	write(STDERR_FILENO, "Error\n", 6);
	perror(origin);
	exit(EXIT_FAILURE);
}
