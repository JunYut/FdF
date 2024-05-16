/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:08:28 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/15 10:10:38 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

void	print_projection(t_line *p, int edges_count)
{
	int	i;

	debug("Printing projection...");
	i = -1;
	while (++i < edges_count)
	{
		ft_printf("Projection %d\n", i);
		ft_printf("Start: %d, %d, %d\n",
			p[i].start.x, p[i].start.y, p[i].start.color);
		ft_printf("End: %d, %d, %d\n", p[i].end.x, p[i].end.y, p[i].end.color);
		ft_printf("\n");
	}
}

void	print_edges(t_line *e, int edges_count)
{
	int	i;

	debug("Printing wireframe...");
	i = -1;
	while (++i < edges_count)
	{
		ft_printf("Edge %d\n", i);
		ft_printf("Start: %d, %d, %d\n",
			e[i].start.x, e[i].start.y, e[i].start.color);
		ft_printf("End: %d, %d, %d\n", e[i].end.x, e[i].end.y, e->end.color);
		ft_printf("\n");
	}
}

void	print_vertices(t_point *v, int vertices_count)
{
	int	i;

	debug("Printing vertices...");
	i = -1;
	while (++i < vertices_count)
	{
		ft_printf("Vertex[%d]: %d, %d, %d, %d\n",
			i, v[i].x, v[i].y, v[i].z, v[i].color);
		ft_printf("\n");
	}
}

void	print_transform(t_wireframe	*w)
{
	debug("Printing transformation...");
	ft_printf("Translate: %d %d\n", w->translate.x, w->translate.y);
	ft_printf("Rotate: %d %d %d\n\n", w->rotate.x, w->rotate.y, w->rotate.z);
}

void	print_center(t_point center)
{
	ft_printf("Center: %d, %d, %d\n", center.x, center.y, center.z);
}
