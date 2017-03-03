/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:53:13 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/02 14:54:09 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_print_modif1(t_fdf *fdf)
{
	char *str;

	if (fdf->modif == 12)
		str = "R]";
	else if (fdf->modif == 13)
		str = "G]";
	else if (fdf->modif == 14)
		str = "B]";
	else
		str = "]";
	mlx_string_put(fdf->mlx, fdf->window, 120, 230, 0x0FFFFFF, str);
	str = "Modif hauteur = ";
	mlx_string_put(fdf->mlx, fdf->window, 40, 260, 0x0FFFFFF, str);
	str = ft_itoa(fdf->modif_h);
	mlx_string_put(fdf->mlx, fdf->window, 190, 260, 0x0FFFFFF, str);
}

void		ft_print_modif(t_fdf *fdf)
{
	char	*str;

	str = "Changer les couleurs : Select Q W E pour R G B";
	mlx_string_put(fdf->mlx, fdf->window, 40, 110, 0x0FFFFFF, str);
	str = "red = ";
	mlx_string_put(fdf->mlx, fdf->window, 100, 140, 0x0FFFFFF, str);
	str = ft_itoa(fdf->red);
	mlx_string_put(fdf->mlx, fdf->window, 200, 140, 0x0FFFFFF, str);
	str = "green = ";
	mlx_string_put(fdf->mlx, fdf->window, 100, 170, 0x0FFFFFF, str);
	str = ft_itoa(fdf->green);
	mlx_string_put(fdf->mlx, fdf->window, 200, 170, 0x0FFFFFF, str);
	str = "blue = ";
	mlx_string_put(fdf->mlx, fdf->window, 100, 200, 0x0FFFFFF, str);
	str = ft_itoa(fdf->blue);
	mlx_string_put(fdf->mlx, fdf->window, 200, 200, 0x0FFFFFF, str);
	str = "Select [";
	mlx_string_put(fdf->mlx, fdf->window, 40, 230, 0x0FFFFFF, str);
	ft_print_modif1(fdf);
}
