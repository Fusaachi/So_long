/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:46:27 by pgiroux           #+#    #+#             */
/*   Updated: 2024/09/10 17:19:42 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_size_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->maps[y] != NULL)
	{
		x = 0;
		while (data->maps[y][x] != '\0')
			x++;
		if (x != data->width)
			return (1);
		y++;
	}
	return (0);
}

int	ft_verif_files(char *argv)
{
	int	n;

	n = ft_strlen(argv);
	if (ft_strncmp(&argv[n - 4], ".ber", 4))
		return (1);
	return (0);
}

int	ft_all_check(t_data *data)
{
	if (ft_check_frame(data) || ft_check_is_c(data) || ft_size_map(data))
	{
		ft_putstr_fd("Error,\nMap isn't valid\n", 2);
		return (0);
	}
	else if (!ft_nb_collect(data))
	{
		ft_putstr_fd("Error,\nNo collectible\n", 2);
		return (0);
	}
	else if (!ft_check_posib(data))
	{
		ft_putstr_fd("Error,\nMap isn't possible\n", 2);
		return (0);
	}
	ft_free(data->maps2);
	return (1);
}

int	ft_verif_arg(int argc, char *argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error,\nNot 2 arguments\n", 2);
		return (1);
	}
	if (ft_verif_files(argv))
	{
		ft_putstr_fd("Error,\nIsn't good files\n", 2);
		return (1);
	}
	return (0);
}
