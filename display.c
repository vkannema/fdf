/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 16:09:43 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/02 14:47:10 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

points	*get_second(t_fdf *fdf, points *first, int call)
{
	int		k;
	points	*second;

	k = 0;
	if (call == 0)
		second = first;
	while (k <= fdf->size_map && second)
	{
		second = second->next;
		k++;
	}
	return (second);
}

void	fill_str_image(t_fdf *fdf, int i, int j, int z)
{
	if (i > 0 && j > 0 && i < WIDTH && j < HEIGHT && z == 0)
	{
		fdf->image_string[((i * 4 + (j * fdf->size_line)))] = fdf->blue;
		fdf->image_string[((i * 4 + (j * fdf->size_line))) + 1] = fdf->green;
		fdf->image_string[((i * 4 + (j * fdf->size_line))) + 2] = fdf->red;
		fdf->image_string[((i * 4 + (j * fdf->size_line))) + 3] = 0;
	}
	else if (i > 0 && j > 0 && i < WIDTH && j < HEIGHT && (z != 0))
	{
		fdf->image_string[((i * 4 + (j * fdf->size_line)))] = fdf->blue;
		fdf->image_string[((i * 4 + (j * fdf->size_line))) + 1] = fdf->green;
		fdf->image_string[((i * 4 + (j * fdf->size_line))) + 2] = fdf->red;
		fdf->image_string[((i * 4 + (j * fdf->size_line))) + 3] = 0;
	}
}

void	ft_columns(t_fdf *fdf, points *first)
{
	int		i;
	int		j;
	int		k;
	points	*second;

	second = get_second(fdf, first, 0);
	while (second)
	{
		k = 0;
		i = first->sx - 1;
		while (i >= second->sx)
		{
			j = ((second->sy - first->sy) * (i - first->sx)) /
			(second->sx - first->sx) + first->sy;
			while (j <= ((second->sy - first->sy) * (i + 1 - first->sx) /
			(second->sx - first->sx)) + first->sy)
				fill_str_image(fdf, i, j++, first->z);
			while (j > ((second->sy - first->sy) * (i + 1 - first->sx) /
			(second->sx - first->sx)) + first->sy)
				fill_str_image(fdf, i, j--, first->z);
			i--;
		}
		first = second;
		second = get_second(fdf, first, 1);
	}
}

void	ft_lines(t_fdf *fdf, points *first, points *second)
{
	int		i;
	int		j;

	if ((second->sx - first->sx == 0))
		return ;
	while (second)
	{
		i = first->sx;
		j = ((second->sy - first->sy) * (i - first->sx)) /
		(second->sx - first->sx) + first->sy;
		while (i < second->sx)
		{
			while (j <= ((second->sy - first->sy) * (i + 1 - first->sx) /
			(second->sx - first->sx)) + first->sy)
				fill_str_image(fdf, i, j++, first->z);
			while (j > ((second->sy - first->sy) * (i + 1 - first->sx) /
			(second->sx - first->sx)) + first->sy)
				fill_str_image(fdf, i, j--, first->z);
			i++;
		}
		first = second;
		second = second->next;
	}
}

int		ft_display(t_fdf *fdf)
{
	points	*tmp;
	int		k;

	k = 0;
	tmp = fdf->start;
	ft_lines(fdf, fdf->start, fdf->start->next);
	while (k <= fdf->size_map)
	{
		ft_columns(fdf, tmp);
		tmp = tmp->next;
		k++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
	return (0);
}
