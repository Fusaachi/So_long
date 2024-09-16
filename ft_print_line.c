/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:01:41 by pgiroux           #+#    #+#             */
/*   Updated: 2024/08/29 15:09:10 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_line(char *line, t_data *d, int x, int y)
{
	int		i;

	i = 0;
	d->img.w_h = 55;
	while (line[i] && line[i] != '\n')
	{
		mlx_put_image_to_window(d->mlx, d->win, d->img.floor, x, y);
		if (line[i] == '1')
			mlx_put_image_to_window(d->mlx, d->win, d->img.wall, x, y);
		else if (line[i] == 'P')
			mlx_put_image_to_window(d->mlx, d->win, d->img.play_b, x, y);
		else if (line[i] == 'C')
			mlx_put_image_to_window(d->mlx, d->win, d->img.item, x, y);
		else if (line[i] == 'E')
			mlx_put_image_to_window(d->mlx, d->win, d->img.exit, x, y);
		i++;
		x += d->img.w_h;
	}
}
