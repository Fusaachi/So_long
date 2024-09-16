/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:27:21 by pgiroux           #+#    #+#             */
/*   Updated: 2024/08/30 16:24:45 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_collect_playable(t_data *data, int y, int x, t_so_long *so_long)
{
	int	ok;

	ok = 0;
	if (so_long->counter == data->nb_collect)
		return (1);
	if (data->maps2[y - 1][x] != '1' && data->maps2[y - 1][x] != '2'
			&& data->maps2[y - 1][x] != 'P' && ok == 0)
		ok = ft_collect_moves(data, y - 1, x, so_long);
	if (data->maps2[y][x + 1] != '1' && data->maps2[y][x + 1] != '2'
			&& data->maps2[y][x + 1] != 'P' && ok == 0)
		ok = ft_collect_moves(data, y, x + 1, so_long);
	if (data->maps2[y + 1][x] != '1' && data->maps2[y + 1][x] != '2'
			&& data->maps2[y + 1][x] != 'P' && ok == 0)
		ok = ft_collect_moves(data, y + 1, x, so_long);
	if (data->maps2[y][x - 1] != '1' && data->maps2[y][x - 1] != '2'
			&& data->maps2[y][x - 1] != 'P' && ok == 0)
		ok = ft_collect_moves(data, y, x - 1, so_long);
	if (ok == 1)
		return (1);
	return (0);
}

int	ft_collect_moves(t_data *data, int y, int x, t_so_long *so_long)
{
	if (data->maps2[y][x] == 'C')
		so_long->counter ++;
	if (data->maps2[y][x] == 'C' || data->maps2[y][x] == '0')
		data->maps2[y][x] = '2';
	return (ft_collect_playable(data, y, x, so_long));
}

int	ft_exit_playable(t_data *data, int y, int x, t_so_long *so_long)
{
	int	ok;

	ok = 0;
	if (data->maps2[y][x] == 'E')
		return (1);
	if (data->maps2[y - 1][x] != '1' && data->maps2[y - 1][x] != '2'
			&& data->maps2[y - 1][x] != 'P' && ok == 0)
		ok = ft_exit_moves(data, y - 1, x, so_long);
	if (data->maps2[y][x + 1] != '1' && data->maps2[y][x + 1] != '2'
			&& data->maps2[y][x + 1] != 'P' && ok == 0)
		ok = ft_exit_moves(data, y, x + 1, so_long);
	if (data->maps2[y + 1][x] != '1' && data->maps2[y + 1][x] != '2'
			&& data->maps2[y + 1][x] != 'P' && ok == 0)
		ok = ft_exit_moves(data, y + 1, x, so_long);
	if (data->maps2[y][x - 1] != '1' && data->maps2[y][x - 1] != '2'
			&& data->maps2[y][x - 1] != 'P' && ok == 0)
		ok = ft_exit_moves(data, y, x - 1, so_long);
	if (ok == 1)
		return (1);
	return (0);
}

int	ft_exit_moves(t_data *data, int y, int x, t_so_long *so_long)
{
	if (data->maps2[y][x] == 'C' || data->maps2[y][x] == '0')
		data->maps2[y][x] = '2';
	return (ft_exit_playable(data, y, x, so_long));
}

void	ft_reset_maps2(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->maps2[y] != NULL)
	{
		x = 0;
		while (data->maps2[y][x] != '\0')
		{
			if (data->maps2[y][x] == '2')
				data->maps2[y][x] = '0';
			x++;
		}
		y++;
	}
}
