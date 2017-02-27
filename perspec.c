/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:51:30 by vkannema          #+#    #+#             */
/*   Updated: 2017/02/26 19:38:12 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

points *ft_iso(t_fdf *fdf)
{
	points	*tmp;

	tmp = fdf->start;
	while (tmp)
	{
		tmp->sx = WIDTH / 2 + (tmp->x - tmp->y) * TILE_WIDTH;
		if (tmp->z != 0)
			tmp->sy = HEIGHT / 2 + (tmp->x + tmp->y) * (TILE_HEIGHT / 2);
		else
			tmp->sy = HEIGHT / 2 + (tmp->x + tmp->y) * (TILE_HEIGHT / 2) + fdf->modif_h;
		tmp = tmp->next;
	}
	return (fdf->start);
}
