# include "wireframe.h"

void	print_wireframe(t_wireframe *wireframe)
{
	debug("Printing wireframe...");
	for (int i = 0; i < wireframe->edges_count; i++)
	{
		ft_printf("Edge %d\n", i);
		ft_printf("Start: %d %d\n", wireframe->edges[i].start.x, wireframe->edges[i].start.y);
		ft_printf("End: %d %d\n", wireframe->edges[i].end.x, wireframe->edges[i].end.y);
		ft_printf("\n");
	}
}

void	print_projection(t_wireframe *wireframe)
{
	debug("Printing projection...");
	for (int i = 0; i < wireframe->edges_count; i++)
	{
		ft_printf("Projection %d\n", i);
		ft_printf("Start: %d %d\n", wireframe->projection[i].start.x, wireframe->projection[i].start.y);
		ft_printf("End: %d %d\n", wireframe->projection[i].end.x, wireframe->projection[i].end.y);
		ft_printf("\n");
	}
}

void	print_vertices(t_wireframe *wireframe)
{
	debug("Printing vertices...");
	for (int i = 0; i < wireframe->vertices_count; i++)
	{
		ft_printf("Vertex %d\n", i);
		ft_printf("Coordinates: %d, %d, %d\n", wireframe->vertices[i].x, wireframe->vertices[i].y, wireframe->vertices[i].z);
		ft_printf("\n");
	}
}

void	print_transform(t_wireframe	*s_wireframe)
{
	debug("Printing transformation...");
	printf("Scale: %f\n", s_wireframe->scale);
	ft_printf("Translate: %d %d\n", s_wireframe->translate.x, s_wireframe->translate.y);
	ft_printf("Rotate: %d %d %d\n", s_wireframe->rotate.x, s_wireframe->rotate.y, s_wireframe->rotate.z);
}

void	print_center(t_wireframe *wireframe)
{
	ft_printf("Center: %d %d\n", wireframe->center.x, wireframe->center.y);
}

void	debug(char *str)
{
	static int i;

	if (str == NULL)
		ft_printf("Debug %d\n", i++);
	else
		ft_printf("Debug %d: %s\n", i++, str);
}
