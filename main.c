/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:45:54 by vkannema          #+#    #+#             */
/*   Updated: 2017/02/27 11:43:40 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		key_hooks(int keycode, t_fdf *fdf)
{
	ft_printf("%d\n", keycode);
	if (keycode == 49)
	{
		fdf->image_string = mlx_get_data_addr(fdf->image, &(fdf->bpp),
			&(fdf->size_line), &(fdf->endian));
		ft_display(fdf);
		mlx_destroy_image(fdf->mlx, fdf->image);
		fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	}
	if (keycode == ESC_KEY)
		exit(0);
	return (0);
}

int		mouse_hook(int button,int x, int y, t_fdf *fdf)
{
	x = 10;
	y = 11;
	ft_printf("%d\n", button);
	if (button == 4)
	{
		fdf->modif_h++;
		fdf->image_string = mlx_get_data_addr(fdf->image, &(fdf->bpp),
			&(fdf->size_line), &(fdf->endian));
		ft_iso(fdf);
		ft_display(fdf);
		mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
		mlx_destroy_image(fdf->mlx, fdf->image);
		fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	}
	if (button == 5)
	{
		fdf->modif_h--;
		fdf->image_string = mlx_get_data_addr(fdf->image, &(fdf->bpp),
			&(fdf->size_line), &(fdf->endian));
		ft_iso(fdf);
		ft_display(fdf);
		mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
		mlx_destroy_image(fdf->mlx, fdf->image);
		fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	}
	return (0);
}
//


static points	*create_el(int x, int y, int z)
{
	points *begin;

	begin = malloc(sizeof(points));
	begin->x = x;
	begin->y = y;
	begin->z = z;
	begin->sx = 0;
	begin->sy = 0;
	begin->next = NULL;
	return (begin);
}

static points	*push_back(points *begin, int x, int y, int z)
{
	points	*tmp;

	tmp = begin;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = malloc(sizeof(points));
	tmp->next->x = x;
	tmp->next->y = y;
	tmp->next->z = z;
	tmp->next->sx = 0;
	tmp->next->sy = 0;
	tmp->next->next = NULL;
	return (begin);
}

static points 	*parse(t_fdf *fdf)
{
	char 	*line;
	char 	**pointstr;
	int 	x;
	int 	y;
	int 	i;
	points 	*begin;

	y = 0;
	x = 0;
	//ft_get_ratio(fdf);
	begin = NULL;
	line = NULL;
	while (get_next_line(fdf->fd, &line))
	{
		i = 0;
		x = 0;
		pointstr = ft_strsplit(line, ' ');
		while (pointstr[i])
		{
			if (begin == NULL)
				begin = create_el(x, y, ft_atoi(pointstr[i]));
			else
				push_back(begin, x, y, ft_atoi(pointstr[i]));
			x++;
			i++;
		}
		y++;
	}
	//begin = ft_add_ratio(begin, fdf);
	ft_printf("ok parse\n");
	return (begin);
}

t_fdf 	*ft_init()
{
	t_fdf *fdf;

	fdf = malloc(sizeof(t_fdf));
	fdf->mlx = NULL;
	fdf->window = NULL;
	fdf->image = NULL;
	fdf->image_string = NULL;
	fdf->fd = 0;
	fdf->red = 0;
	fdf->green = 0;
	fdf->blue = 0;
	fdf->start = NULL;
	fdf->modif_h = 10;
	fdf->t_w = 10;
	fdf->t_h = 10;
	return (fdf);
}

static void	ft_build(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "wesh");
	fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	mlx_hook(fdf->window,2, 2, key_hooks, fdf);
	mlx_mouse_hook(fdf->window, mouse_hook, fdf);
	// fdf->image_string= mlx_get_data_addr(fdf->image, &(fdf->bpp), &(fdf->size_line), &(fdf->endian));
	// ft_display(fdf);
	// mlx_destroy_image(fdf->mlx, fdf->image);
	// fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	mlx_loop(fdf->mlx);
}

int 	main(int ac, char **av)
{
	t_fdf	*fdf;
	//points 	*tmp;

	ft_printf("on commence\n");
	fdf = ft_init();
	if (ac != 2)
		return (0);
	fdf->fd = open(av[1], O_RDONLY);
	fdf->start = parse(fdf);
	fdf->start = ft_iso(fdf);
	// tmp = fdf->start;
	// while (tmp)
	// {
	//  	ft_printf("%d %d %d\n", tmp->x, tmp->y, tmp->z);
	// 	tmp = tmp->next;
	// }
	ft_build(fdf);
	return (0);
}
