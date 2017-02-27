/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 16:09:43 by vkannema          #+#    #+#             */
/*   Updated: 2017/02/27 11:46:29 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void fill_pixel(t_fdf *fdf)
{
	points	*tmp;
	int		pos;

	tmp = fdf->start;
	while (tmp)
	{
		pos = WIDTH * 4 * sizeof(char) * tmp->sy + (4 * sizeof(char) * tmp->sx);
		if (tmp->z == 0)
		{
			fdf->image_string[pos] = 0;
			fdf->image_string[pos + 1] = 255;
			fdf->image_string[pos + 2] = 255;
			fdf->image_string[pos + 3] = 0;
		}
		else
		{
			fdf->image_string[pos] = 0;
			fdf->image_string[pos + 1] = 0;
			fdf->image_string[pos + 2] = 255;
			fdf->image_string[pos + 3] = 0;
		}
		tmp = tmp->next;
	}
}

int		ft_display(t_fdf *fdf)
{
	fdf->red = 0;
	fdf->green = 0;
	fdf->blue = 255;
	fill_pixel(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
	return (0);
}
