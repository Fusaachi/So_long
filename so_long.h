/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:07:25 by pgiroux           #+#    #+#             */
/*   Updated: 2024/09/10 17:20:04 by pgiroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <X11/keysym.h>

typedef struct s_img
{
	void	*floor;
	void	*wall;
	void	*play_r;
	void	*play_l;
	void	*play_b;
	void	*play_t;
	void	*exit_p;
	void	*exit;
	void	*par;
	void	*item;
	int		w_h;
}	t_img;
typedef struct s_so_long
{
	int		i;
	int		fd;
	int		counter;
	char	*map;
	char	*line;
}t_so_long;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		fd;
	int		w_h;
	int		win_h;
	int		win_w;
	char	*line;
	char	*map;
	char	**maps;
	char	**maps2;
	int		exit_x;
	int		exit_y;
	int		x;
	int		y;
	int		width;
	int		height;
	int		pos_x;
	int		pos_y;
	int		collectibles;
	int		nb_collect;
	int		mouv;
	t_img	img;
}	t_data;

int		main(int argc, char **argv);
int		ft_init_so_long(t_so_long *so_long, char *argv);
void	ft_read_map(t_so_long *so_long, t_data *data);
int		ft_create_windows(t_data *data, t_so_long *so_long);
void	ft_create_map(t_data *data, t_so_long *so_long);
void	ft_print_line(char *line, t_data *d, int x, int y);
int		ft_width(t_data *data);
int		ft_height(t_data *data);
int		ft_verif_arg(int argc, char *argv);
int		my_keyhook(int keysym, t_data *d);
void	ft_init_img(t_data *d);
int		ft_position_x(t_data *data);
int		ft_position_y(t_data *data);
int		ft_exit_x(t_data *data);
int		ft_exit_y(t_data *data);
void	ft_left(t_data *d);
void	ft_right(t_data *d);
void	ft_down(t_data *d);
void	ft_up(t_data *d);
void	ft_init_data(t_data *data, char *map);
int		ft_check_doublon(t_data *data);
int		ft_check_frame(t_data *data);
int		ft_check_frame2(t_data *data, int y);
int		ft_all_check(t_data *data);
int		ft_mouse(t_data *data);
int		ft_nb_collect(t_data *data);
void	ft_destroy(t_data *data, int i);
void	ft_destroy_img(t_data *data);
int		ft_check_posib(t_data *data);
int		ft_check_is_c(t_data *data);
int		ft_size_map(t_data *data);
int		ft_collect_playable(t_data *data, int y, int x, t_so_long *so);
int		ft_collect_moves(t_data *data, int y, int x, t_so_long *so);
int		ft_exit_playable(t_data *data, int y, int x, t_so_long *so);
int		ft_exit_moves(t_data *data, int y, int x, t_so_long *so);
void	ft_reset_maps2(t_data *data);
void	finish(t_data *data);
int		ft_verif_files(char *argv);

#endif