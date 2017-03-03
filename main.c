/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:45:54 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/02 15:10:03 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf			*ft_init(void)
{
	t_fdf *fdf;

	fdf = malloc(sizeof(t_fdf));
	fdf->mlx = NULL;
	fdf->window = NULL;
	fdf->image = NULL;
	fdf->image_string = NULL;
	fdf->fd = 0;
	fdf->red = 255;
	fdf->green = 255;
	fdf->blue = 255;
	fdf->start = NULL;
	fdf->modif_h = 0;
	fdf->t_w = 10;
	fdf->t_h = 10;
	fdf->size_map = 0;
	fdf->modif = 1;
	fdf->did = 0;
	fdf->bred = 255;
	fdf->bblue = 255;
	fdf->bgreen = 255;
	fdf->max_x = 0;
	return (fdf);
}

int				check_map(t_fdf *fdf)
{
	int		i;
	int		x;
	int		y;
	char	*line;
	char	**pointstr;

	y = 0;
	while (get_next_line(fdf->fd, &line))
	{
		x = 0;
		i = 0;
		pointstr = ft_strsplit(line, ' ');
		while (pointstr[i])
		{
			x++;
			i++;
		}
		y++;
		if (fdf->max_x == 0)
			fdf->max_x = x;
		if (fdf->max_x != x)
			return (0);
	}
	return (1);
}

int				ft_check_one(t_fdf *fdf)
{
	int		i;
	points	*tmp;

	i = 0;
	tmp = fdf->start;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (i == 1)
		return (0);
	return (1);
}

int				get_size(t_fdf *fdf)
{
	points	*tmp;
	int		ret;

	ret = 0;
	tmp = fdf->start;
	while (tmp)
	{
		if (tmp->x > ret)
			ret = tmp->x;
		tmp = tmp->next;
	}
	return (ret);
}

int				main(int ac, char **av)
{
	t_fdf	*fdf;

	fdf = ft_init();
	if (ac != 2)
	{
		ft_printf("Usage : ./fdf map\n");
		return (0);
	}
	fdf->fd = open(av[1], O_RDONLY);
	if (fdf->fd < 0)
		return (0);
	fdf->start = parse(fdf);
	fdf->fd = close(fdf->fd);
	fdf->fd = open(av[1], O_RDONLY);
	if ((check_map(fdf)) == 0 || ft_check_one(fdf) == 0 || fdf->start == NULL)
	{
		ft_memdel((void **)&fdf);
		ft_printf("Invalid map\n");
		return (0);
	}
	ft_build(fdf);
	close(fdf->fd);
	ft_memdel((void **)&fdf);
	return (0);
}
