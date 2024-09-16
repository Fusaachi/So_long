/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:16:03 by pgiroux           #+#    #+#             */
/*   Updated: 2024/09/10 13:36:59 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read_map(t_so_long *so_long, t_data *data)
{
	int	line_is_empty;

	line_is_empty = 0;
	while (so_long->line != NULL)
	{
		so_long->map = ft_strjoin_gnl(so_long->map, so_long->line);
		free(so_long->line);
		so_long->line = get_next_line(so_long->fd);
		if (so_long->line && so_long->line[0] && so_long->line[0] != '\n'
			&& line_is_empty)
		{
			free(so_long->map);
			free(so_long->line);
			exit(1);
		}
		if (so_long->line && so_long->line[0] == '\n')
			line_is_empty = 1;
	}
	ft_init_data(data, so_long->map);
}

int	ft_width(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->width)
		i++;
	return (i);
}

int	ft_height(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height)
		i++;
	return (i);
}

int	ft_create_windows(t_data *data, t_so_long *so_long)
{
	data->win_w = ft_width(data) * data->w_h;
	data->win_h = ft_height(data) * data->w_h;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->win = mlx_new_window(data->mlx, data->win_w, data->win_h, "so long");
	if (!data->win)
		return (free(data->mlx), 1);
	else
		return (0);
	close(so_long->fd);
}

void	ft_create_map(t_data *data, t_so_long *so_long)
{
	ft_init_img(data);
	while (data->maps[so_long->i] != NULL)
	{
		ft_print_line(data->maps[so_long->i], data, data->x, data->y);
		data->y += data->w_h;
		so_long->i++;
	}
	data->y = ft_position_y(data) * 55;
	data->x = ft_position_x(data) * 55;
	mlx_key_hook(data->win, &my_keyhook, data);
	data->nb_collect = ft_nb_collect(data);
	mlx_hook(data->win, 17, 0, &ft_mouse, data);
	mlx_loop(data->mlx);
	ft_destroy(data, EXIT_SUCCESS);
}
