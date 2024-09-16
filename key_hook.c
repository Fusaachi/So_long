/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:54:21 by pgiroux           #+#    #+#             */
/*   Updated: 2024/09/13 09:34:44 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	my_keyhook(int keysym, t_data *d)
{
	char	*mouv;

	if (keysym == XK_Left || keysym == XK_a)
		ft_left(d);
	else if (keysym == XK_Right || keysym == XK_d)
		ft_right(d);
	else if (keysym == XK_Down || keysym == XK_s)
		ft_down(d);
	else if (keysym == XK_Up || keysym == XK_w)
		ft_up(d);
	else if (keysym == XK_Escape)
		ft_destroy(d, EXIT_SUCCESS);
	mouv = ft_itoa(d->mouv);
	mlx_put_image_to_window(d->mlx, d->win, d->img.par, 10, 10);
	mlx_string_put(d->mlx, d->win, 22, 30, 0, "Nombre de mouvements");
	mlx_string_put(d->mlx, d->win, 147, 30, 0, mouv);
	free(mouv);
	return (0);
}

void	ft_left(t_data *d)
{
	if (d->maps[d->y / 55][d->x / 55 - 1] == '1')
		ft_putstr_fd("Error,\nThere is a tree \n", 0);
	else if (d->maps[d->y / 55][d->x / 55] == 'E')
	{
		d->mouv ++;
		mlx_put_image_to_window(d->mlx, d->win, d->img.exit, d->x, d->y);
		d->x -= 55;
		mlx_put_image_to_window(d->mlx, d->win, d->img.play_l, d->x, d->y);
	}
	else
	{	
		d->mouv ++;
		mlx_put_image_to_window(d->mlx, d->win, d->img.floor, d->x, d->y);
		d->x -= 55;
		if (d->maps[d->y / 55][d->x / 55] == 'E')
			finish(d);
		else
			mlx_put_image_to_window(d->mlx, d->win, d->img.play_l, d->x, d->y);
	}
	if (d->maps[d->y / 55][d->x / 55] == 'C')
	{
		d->collectibles += 1;
		d->maps[d->y / 55][d->x / 55] = '0';
	}
}

void	ft_right(t_data *d)
{
	if (d->maps[d->y / 55][d->x / 55 + 1] == '1')
		ft_putstr_fd("Error,\nThere is a tree\n", 0);
	else if (d->maps[d->y / 55][d->x / 55] == 'E')
	{
		d->mouv ++;
		mlx_put_image_to_window(d->mlx, d->win, d->img.exit, d->x, d->y);
		d->x += 55;
		mlx_put_image_to_window(d->mlx, d->win, d->img.play_r, d->x, d->y);
	}
	else
	{
		d->mouv ++;
		mlx_put_image_to_window(d->mlx, d->win, d->img.floor, d->x, d->y);
		d->x += 55;
		if (d->maps[d->y / 55][d->x / 55] == 'E')
			finish(d);
		else
			mlx_put_image_to_window(d->mlx, d->win, d->img.play_r, d->x, d->y);
	}
	if (d->maps[d->y / 55][d->x / 55] == 'C')
	{
		d->collectibles += 1;
		d->maps[d->y / 55][d->x / 55] = '0';
	}
}

void	ft_up(t_data *d)
{
	if (d->maps[d->y / 55 - 1][d->x / 55] == '1')
		ft_putstr_fd("Error,\nThere is a tree\n", 0);
	else if (d->maps[d->y / 55][d->x / 55] == 'E')
	{
		d->mouv ++;
		mlx_put_image_to_window(d->mlx, d->win, d->img.exit, d->x, d->y);
		d->y -= 55;
		mlx_put_image_to_window(d->mlx, d->win, d->img.play_t, d->x, d->y);
	}
	else
	{
		d->mouv ++;
		mlx_put_image_to_window(d->mlx, d->win, d->img.floor, d->x, d->y);
		d->y -= 55;
		if (d->maps[d->y / 55][d->x / 55] == 'E')
			finish(d);
		else
			mlx_put_image_to_window(d->mlx, d->win, d->img.play_t, d->x, d->y);
	}
	if (d->maps[d->y / 55][d->x / 55] == 'C')
	{
		d->collectibles += 1;
		d->maps[d->y / 55][d->x / 55] = '0';
	}
}

void	ft_down(t_data *d)
{
	if (d->maps[d->y / 55 + 1][d->x / 55] == '1')
		ft_putstr_fd("Error,\nThere is a tree\n", 0);
	else if (d->maps[d->y / 55][d->x / 55] == 'E')
	{
		d->mouv ++;
		mlx_put_image_to_window(d->mlx, d->win, d->img.exit, d->x, d->y);
		d->y += 55;
		mlx_put_image_to_window(d->mlx, d->win, d->img.play_b, d->x, d->y);
	}
	else
	{
		d->mouv ++;
		mlx_put_image_to_window(d->mlx, d->win, d->img.floor, d->x, d->y);
		d->y += 55;
		if (d->maps[d->y / 55][d->x / 55] == 'E')
			finish(d);
		else
			mlx_put_image_to_window(d->mlx, d->win, d->img.play_b, d->x, d->y);
	}
	if (d->maps[d->y / 55][d->x / 55] == 'C')
	{
		d->collectibles += 1;
		d->maps[d->y / 55][d->x / 55] = '0';
	}
}
