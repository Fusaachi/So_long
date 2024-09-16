/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:00:04 by pgiroux           #+#    #+#             */
/*   Updated: 2024/09/10 17:20:25 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mouse(t_data *data)
{
	ft_destroy(data, EXIT_SUCCESS);
	return (0);
}

void	ft_destroy(t_data *data, int i)
{
	ft_destroy_img(data);
	mlx_loop_end(data->mlx);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	ft_free(data->maps);
	free(data->mlx);
	exit(i);
}

void	ft_destroy_img(t_data *data)
{
	if (data->img.wall)
		mlx_destroy_image(data->mlx, data->img.wall);
	if (data->img.floor)
		mlx_destroy_image(data->mlx, data->img.floor);
	if (data->img.play_r)
		mlx_destroy_image(data->mlx, data->img.play_r);
	if (data->img.item)
		mlx_destroy_image(data->mlx, data->img.item);
	if (data->img.exit)
		mlx_destroy_image(data->mlx, data->img.exit);
	if (data->img.exit_p)
		mlx_destroy_image(data->mlx, data->img.exit_p);
	if (data->img.play_l)
		mlx_destroy_image(data->mlx, data->img.play_l);
	if (data->img.play_b)
		mlx_destroy_image(data->mlx, data->img.play_b);
	if (data->img.play_t)
		mlx_destroy_image(data->mlx, data->img.play_t);
	if (data->img.par)
		mlx_destroy_image(data->mlx, data->img.par);
}
