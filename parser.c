/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:19:17 by vkannema          #+#    #+#             */
/*   Updated: 2017/03/02 15:07:42 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int				parse2(t_fdf *fdf, char **pointstr, int x, int y)
{
	int	i;

	i = 0;
	if (ft_isalnum(ft_atoi(pointstr[i])))
		return (0);
	while (pointstr[i])
	{
		if (fdf->start == NULL)
			fdf->start = create_el(x, y, ft_atoi(pointstr[i]));
		else
			push_back(fdf->start, x, y, ft_atoi(pointstr[i]));
		x++;
		i++;
	}
	return (1);
}

points			*parse(t_fdf *fdf)
{
	char	*line;
	char	**pointstr;
	int		x;
	int		y;
	int		i;

	line = NULL;
	y = 0;
	while (get_next_line(fdf->fd, &line))
	{
		i = 0;
		x = 0;
		if (ft_strlen(line) <= 1)
			return (NULL);
		pointstr = ft_strsplit(line, ' ');
		if (parse2(fdf, pointstr, x, y) == 0)
			return (NULL);
		y++;
	}
	return (fdf->start);
}
