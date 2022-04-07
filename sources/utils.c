/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:31:04 by agouet            #+#    #+#             */
/*   Updated: 2022/04/01 16:37:56 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int n)
{
	unsigned int	number;
	int				len;

	len = 1;
	if (n < 0)
	{
		len += ft_putchar('-');
		number = (-n);
	}
	else
		number = n;
	if (number > 9)
	{
		len += ft_putnbr(number / 10);
		ft_putnbr(number % 10);
	}
	else
		ft_putchar(number + '0');
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((char) *s == (char) c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	str = (char *) malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_free(t_data *data)
{
	free(data->map.map);
	free(data->map.cut_map);
	free(data->pt_mlx);
	return (0);
}
