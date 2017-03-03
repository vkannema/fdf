/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:08:56 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/02 13:23:07 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_key7(int keycode, t_fdf *fdf)
{
	if (keycode == 69)
	{
		fdf->button = 69;
		fdf->t_w += 2;
		fdf->t_h += 2;
	}
	if (keycode == 29)
	{
		fdf->did = 0;
		fdf->bred = 255;
		fdf->bgreen = 255;
		fdf->bblue = 255;
		fdf->red = 255;
		fdf->blue = 255;
		fdf->green = 255;
	}
	ft_loop(fdf);
	return (0);
}

int		key_hooks(int keycode, t_fdf *fdf)
{
	ft_activate(keycode, fdf);
	if (keycode == ESC_KEY)
		exit(0);
	if (keycode == 12)
	{
		fdf->red += 15;
		if (fdf->red > 255)
			fdf->red = 0;
	}
	ft_key2(keycode, fdf);
	return (0);
}
