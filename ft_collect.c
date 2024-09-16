/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:41:05 by pgiroux           #+#    #+#             */
/*   Updated: 2024/09/10 13:47:18 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_nb_collect(t_data *data)
{
	int	x;
	int	y;
	int	nb;

	y = 0;
	nb = 0;
	while (data->maps[y] != NULL)
	{
		x = 0;
		while (data->maps[y][x] != '\0')
		{
			if (data->maps[y][x] == 'C')
			nb ++;
			x++;
		}
		y++;
	}
	if (nb == 0)
		return (0);
	return (nb);
}

void	finish(t_data *d)
{
	mlx_put_image_to_window(d->mlx, d->win, d->img.exit_p, d->x, d->y);
	if (d->collectibles == d->nb_collect)
	{
		printf("nombre de mouvement :%i\n", d->mouv);
		ft_putstr_fd("*************\n***YOU WIN***\n*************\n", 0);
		ft_destroy(d, EXIT_SUCCESS);
		free(d->mlx);
	}
}
