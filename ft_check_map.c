/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:33:25 by pgiroux           #+#    #+#             */
/*   Updated: 2024/09/10 17:24:24 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_doublon(t_data *data)
{
	int	x;
	int	y;
	int	position;
	int	exit;

	y = 0;
	position = 0;
	exit = 0;
	while (data->maps[y] != NULL)
	{
		x = 0;
		while (data->maps[y][x] != '\0')
		{	
			if (data->maps[y][x] == 'P')
				position++;
			if (data->maps[y][x] == 'E')
				exit++;
			x++;
		}
		y++;
	}
	if (position != 1 || exit != 1)
		return (1);
	return (0);
}

int	ft_check_frame(t_data *data)
{
	int	x;		
	int	y;

	y = 0;
	x = 0;
	while (data->maps[0][x] != '\0')
	{
		if (data->maps[0][x] != '1')
			return (1);
		x++;
		data->width++;
	}		
	while (data->maps[y] != NULL)
	{
		if (data->maps[y][0] != '1')
			return (1);
		data->height++;
		y++;
	}
	if (ft_check_frame2(data, y))
		return (1);
	return (0);
}

int	ft_check_frame2(t_data *data, int y)
{	
	int	x;

	x = 0;
	while (data->maps[y - 1][x] != '\0')
	{
		if (data->maps[y - 1][x] != '1')
			return (1);
		x++;
	}
	y = 0;
	while (data->maps[y] != NULL)
	{
		if (data->maps[y][x - 1] != '1')
			return (1);
		y++;
	}
	return (0);
}

int	ft_check_is_c(t_data *data)
{	
	int	x;
	int	y;
	int	check;

	y = 0;
	while (data->maps[y] != NULL)
	{
		x = 0;
		while (data->maps[y][x] != '\0')
		{
			check = data->maps[y][x];
			if (check != '1' && check != '0' && check != 'P' && check != 'C'
				&& check != 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_check_posib(t_data *data)
{
	t_so_long	so_long;

	so_long.counter = 0;
	if (data->maps2 == NULL)
		return (1);
	if (ft_collect_playable(data, data->pos_y, data->pos_x, &so_long) == 0)
		return (0);
	ft_reset_maps2(data);
	if (!ft_exit_playable(data, data->pos_y, data->pos_x, &so_long))
		return (0);
	return (1);
}
