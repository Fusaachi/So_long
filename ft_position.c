/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:31:17 by pgiroux           #+#    #+#             */
/*   Updated: 2024/08/30 15:15:57 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_position_x(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->maps[y][x] != 'P')
	{
		if (data->maps[y][x] == '\0')
		{
			y++;
			x = 0;
		}
		else
			x++;
	}
	return (x);
}

int	ft_position_y(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->maps[y][x] != 'P')
	{
		if (data->maps[y][x] == '\0')
		{
			y++;
			x = 0;
		}
		else
			x++;
	}
	return (y);
}

int	ft_exit_x(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->maps[y][x] != 'P')
	{
		if (data->maps[y][x] == '\0')
		{
			y++;
			x = 0;
		}
		else
			x++;
	}
	return (x * 55);
}

int	ft_exit_y(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->maps[y][x] != 'P')
	{
		if (data->maps[y][x] == '\0')
		{
			y++;
			x = 0;
		}
		else
			x++;
	}
	return (y * 55);
}
