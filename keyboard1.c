/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:47:08 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/02 13:13:03 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key6(t_fdf *fdf)
{
	points *tmp;

	tmp = fdf->start;
	fdf->button = 78;
	fdf->t_w -= 2;
	fdf->t_h -= 2;
	return (0);
}

int		ft_key5(int keycode, t_fdf *fdf)
{
	points	*tmp;

	tmp = fdf->start;
	if (fdf->modif == 11)
	{
		if (keycode == 18)
		{
			fdf->bred = 255;
			fdf->bgreen = 0;
			fdf->bblue = 0;
		}
	}
	if (keycode == 78)
		ft_key6(fdf);
	ft_key7(keycode, fdf);
	return (0);
}

int		ft_key4(int keycode, t_fdf *fdf)
{
	points	*tmp;

	tmp = fdf->start;
	if (keycode == 125)
	{
		while (tmp)
		{
			tmp->y++;
			tmp->x++;
			tmp = tmp->next;
		}
	}
	else if (keycode == 123)
	{
		while (tmp)
		{
			tmp->y++;
			tmp->x--;
			tmp = tmp->next;
		}
	}
	return (0);
}

int		ft_key3(int keycode, t_fdf *fdf)
{
	points	*tmp;

	tmp = fdf->start;
	if (keycode == 126)
	{
		while (tmp)
		{
			tmp->y--;
			tmp->x--;
			tmp = tmp->next;
		}
	}
	else if (keycode == 124)
	{
		while (tmp)
		{
			tmp->x++;
			tmp->y--;
			tmp = tmp->next;
		}
	}
	ft_key4(keycode, fdf);
	return (0);
}

int		ft_key2(int keycode, t_fdf *fdf)
{
	if (keycode == 13)
	{
		fdf->green += 15;
		if (fdf->green > 255)
			fdf->green = 0;
	}
	if (keycode == 14)
	{
		fdf->blue += 15;
		if (fdf->blue > 255)
			fdf->blue = 0;
	}
	if (fdf->modif == 0)
	{
		fdf->blue = 255;
		fdf->green = 255;
		fdf->red = 255;
	}
	ft_key3(keycode, fdf);
	ft_key5(keycode, fdf);
	return (0);
}
