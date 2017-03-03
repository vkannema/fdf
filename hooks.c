/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:26:49 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/02 14:34:30 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_activate(int keycode, t_fdf *fdf)
{
	if (keycode == 11)
		fdf->modif = 11;
	if (keycode == 15)
		fdf->modif = 0;
}

int				mouse_hook(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		fdf->modif_h++;
		fdf->button = button;
	}
	if (button == 5)
	{
		fdf->modif_h--;
		fdf->button = button;
	}
	ft_loop(fdf);
	return (0);
}

void			ft_loop(t_fdf *fdf)
{
	fdf->image_string = mlx_get_data_addr(fdf->image, &(fdf->bpp),
		&(fdf->size_line), &(fdf->endian));
	ft_iso(fdf);
	ft_display(fdf);
	fdf->button = 0;
	mlx_destroy_image(fdf->mlx, fdf->image);
	fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	ft_print_modif(fdf);
}

void			ft_build(t_fdf *fdf)
{
	fdf->size_map = get_size(fdf);
	fdf->start = ft_iso(fdf);
	fdf->mlx = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "wesh");
	fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->image_string = mlx_get_data_addr(fdf->image, &(fdf->bpp),
		&(fdf->size_line), &(fdf->endian));
	ft_display(fdf);
	mlx_destroy_image(fdf->mlx, fdf->image);
	fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	mlx_hook(fdf->window, 2, 2, key_hooks, fdf);
	mlx_mouse_hook(fdf->window, mouse_hook, fdf);
	mlx_loop(fdf->mlx);
}
