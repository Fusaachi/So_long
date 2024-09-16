/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:47:38 by pgiroux           #+#    #+#             */
/*   Updated: 2024/09/10 17:19:22 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

# include<stdio.h>
# include<fcntl.h>
# include<stdlib.h>
# include<unistd.h>

void	ft_putchar(char c);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
void	ft_free(char **strs);
char	*get_next_line(int fd);
char	*ft_init(char *cp);
char	*ft_strjoin_gnl(char *str, char *buffer);
int		ft_check(char *buffer);
char	*ft_clearbuffer(char *buffer, int i);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *first, const char *second, size_t n);
char	*ft_itoa(int n);

#endif