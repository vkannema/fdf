/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:51:30 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/02 14:35:14 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

points	*ft_i2(t_fdf *fdf)
{
	points *tmp;

	tmp = fdf->start;
	while (tmp)
	{
		if (tmp->z != 0 && fdf->button == 4)
			tmp->sy -= tmp->z;
		else if (tmp->z != 0 && fdf->button == 5)
			tmp->sy += tmp->z;
		else if (fdf->modif_h != 0)
		{
			tmp->sx = WIDTH / 2 + (tmp->x - tmp->y) * fdf->t_w;
			tmp->sy = HEIGHT / 2 + (tmp->x + tmp->y) * (fdf->t_h / 2) -
			(tmp->z * fdf->modif_h);
		}
		else
		{
			tmp->sx = WIDTH / 2 + (tmp->x - tmp->y) * fdf->t_w;
			tmp->sy = HEIGHT / 2 + (tmp->x + tmp->y) * (fdf->t_h / 2) -
			(tmp->z);
		}
		tmp = tmp->next;
	}
	ft_print_modif(fdf);
	return (fdf->start);
}

points	*ft_iso(t_fdf *fdf)
{
	points	*tmp;

	if (fdf->did == 1)
		return (ft_i2(fdf));
	tmp = fdf->start;
	while (tmp)
	{
		if (tmp->z != 0 && fdf->button == 4)
			tmp->sy -= tmp->z;
		else if (tmp->z != 0 && fdf->button == 5)
			tmp->sy += tmp->z;
		else
		{
			tmp->sx = WIDTH / 2 + (tmp->x - tmp->y) * fdf->t_w;
			tmp->sy = HEIGHT / 2 + (tmp->x + tmp->y) * (fdf->t_h / 2) -
			(tmp->z);
		}
		tmp = tmp->next;
	}
	fdf->did = 1;
	return (fdf->start);
}
