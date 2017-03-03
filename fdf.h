/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 14:44:43 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/03 11:35:42 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 2560
# define HEIGHT 1440
# define ESC_KEY 53
# define TILE_WIDTH 30
# define TILE_HEIGHT 30
# define SRED 12
# define SBLUE 13
# define SGREEN 14
# include <mlx.h>
# include <libftprintf.h>

typedef struct		s_points
{
	int				x;
	int				y;
	int				z;
	int				sx;
	int				sy;
	struct s_points	*next;
}					points;

typedef struct		s_fdf
{
	void			*mlx;
	void			*window;
	void			*image;
	char			*image_string;
	int				bpp;
	int				size_line;
	int				endian;
	int				fd;
	int				red;
	int				green;
	int				blue;
	points			*start;
	int				modif_h;
	int				t_h;
	int				t_w;
	int				size_map;
	int				modif;
	int				did;
	int				button;
	int				bred;
	int				bblue;
	int				bgreen;
	int				max_x;
}					t_fdf;

int					ft_display(t_fdf *fdf);
points				*ft_iso(t_fdf *fdf);
points				*parse(t_fdf *fdf);
void				ft_loop(t_fdf *fdf);
void				ft_build(t_fdf *fdf);
void				ft_print_modif(t_fdf *fdf);
int					key_hooks(int keycode, t_fdf *fdf);
int					ft_key7(int keycode, t_fdf *fdf);
int					ft_key2(int keycode, t_fdf *fdf);
void				ft_activate(int keycode, t_fdf *fdf);
int					check_map(t_fdf *fdf);
int					get_size(t_fdf *fdf);
#endif
