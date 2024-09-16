/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:01:46 by pgiroux           #+#    #+#             */
/*   Updated: 2024/09/10 13:46:13 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data		data;
	t_so_long	so_long;

	if (ft_verif_arg(argc, argv[1]))
		return (0);
	if (!ft_init_so_long(&so_long, argv[1]))
		return (0);
	so_long.line = get_next_line(so_long.fd);
	if (!so_long.line)
	{
		ft_putstr_fd("Error,\nEmpty files\n", 2);
		free(so_long.map);
		return (0);
	}
	ft_read_map(&so_long, &data);
	if (!ft_all_check(&data))
	{
		ft_free(data.maps2);
		ft_free(data.maps);
		return (0);
	}
	if (ft_create_windows(&data, &so_long))
		return (0);
	ft_create_map(&data, &so_long);
	return (0);
}
