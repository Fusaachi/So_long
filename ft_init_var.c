/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:00:28 by pgiroux           #+#    #+#             */
/*   Updated: 2024/09/10 17:23:38 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_img(t_data *d)
{
	int	w_h;
	int	w_par;
	int	h_par;

	w_h = 55;
	w_par = 160;
	h_par = 30;
	d->img.wall = mlx_xpm_file_to_image(d->mlx, "img/w.xpm", &w_h, &w_h);
	d->img.floor = mlx_xpm_file_to_image(d->mlx, "img/f.xpm", &w_h, &w_h);
	d->img.play_r = mlx_xpm_file_to_image(d->mlx, "img/p.xpm", &w_h, &w_h);
	d->img.item = mlx_xpm_file_to_image(d->mlx, "img/c.xpm", &w_h, &w_h);
	d->img.exit = mlx_xpm_file_to_image(d->mlx, "img/e.xpm", &w_h, &w_h);
	d->img.exit_p = mlx_xpm_file_to_image(d->mlx, "img/e_p.xpm", &w_h, &w_h);
	d->img.play_l = mlx_xpm_file_to_image(d->mlx, "img/p_l.xpm", &w_h, &w_h);
	d->img.play_b = mlx_xpm_file_to_image(d->mlx, "img/p_b.xpm", &w_h, &w_h);
	d->img.play_t = mlx_xpm_file_to_image(d->mlx, "img/p_t.xpm", &w_h, &w_h);
	d->img.par = mlx_xpm_file_to_image(d->mlx, "img/par.xpm", &w_par, &h_par);
	if (!d->img.wall || !d->img.floor || !d->img.play_r || !d->img.item
		|| !d->img.exit || !d->img.exit_p || !d->img.play_l || !d->img.play_b
		|| !d->img.play_t || !d->img.par)
		ft_destroy(d, EXIT_FAILURE);
}

void	ft_init_data(t_data *data, char *map)
{
	data->y = 0;
	data->x = 0;
	data->maps = ft_split(map, '\n');
	data->maps2 = ft_split(map, '\n');
	if (ft_check_doublon(data))
	{
		ft_putstr_fd("Error,\nNot the right number of characters\n", 2);
		free(map);
		ft_free(data->maps2);
		ft_free(data->maps);
		exit(1);
	}
	data->pos_x = ft_position_x(data);
	data->pos_y = ft_position_y(data);
	data->height = 0;
	data->width = 0;
	data->w_h = 55;
	data->collectibles = 0;
	data->nb_collect = ft_nb_collect(data);
	data->mouv = 0;
	free(map);
}

int	ft_init_so_long(t_so_long *so_long, char *argv)
{
	so_long->fd = open(argv, O_RDONLY);
	if (so_long->fd == -1)
	{
		ft_putstr_fd("Error,\nFile doesn't exist\n", 2);
		return (0);
	}
	so_long->i = 0;
	so_long->map = ft_init("");
	return (1);
}
