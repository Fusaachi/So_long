/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:57:05 by pgiroux           #+#    #+#             */
/*   Updated: 2024/09/04 13:33:45 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *first, const char *second, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (first[i] != '\0' && first[i] == second[i] && i < n - 1)
		i++;
	return ((unsigned char)first[i] - (unsigned char)second[i]);
}
