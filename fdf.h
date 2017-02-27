/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 14:44:43 by vkannema          #+#    #+#             */
/*   Updated: 2017/02/26 19:42:53 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 2560
# define HEIGHT 1440
# define ESC_KEY 53
# define TILE_WIDTH 10
# define TILE_HEIGHT 10
#include "./minilibx_macos/mlx.h"
#include <libftprintf.h>

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
}					t_fdf;



int					ft_display(t_fdf *fdf);
points				*ft_iso(t_fdf *fdf);
#endif
