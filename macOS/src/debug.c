# include "wireframe.h"

void	print_projection(t_line *projection, int edges_count)
{
	debug("Printing projection...");
	for (int i = 0; i < edges_count; i++)
	{
		ft_printf("Projection %d\n", i);
		ft_printf("Start: %d, %d, %d\n", projection[i].start.x, projection[i].start.y, projection[i].start.color);
		ft_printf("End: %d, %d, %d\n", projection[i].end.x, projection[i].end.y, projection[i].end.color);
		ft_printf("\n");
	}
}

void	print_edges(t_line *edges, int edges_count)
{
	debug("Printing wireframe...");
	for (int i = 0; i < edges_count; i++)
	{
		ft_printf("Edge %d\n", i);
		ft_printf("Start: %d, %d, %d\n", edges[i].start.x, edges[i].start.y, edges[i].start.color);
		ft_printf("End: %d, %d, %d\n", edges[i].end.x, edges[i].end.y, edges->end.color);
		ft_printf("\n");
	}
}

void	print_vertices(t_point *vertices, int vertices_count)
{
	debug("Printing vertices...");
	for (int i = 0; i < vertices_count; i++)
	{
		ft_printf("Vertex[%d]: %d, %d, %d, %d\n", i, vertices[i].x, vertices[i].y, vertices[i].z, vertices[i].color);
		ft_printf("\n");
	}
}

void	print_transform(t_wireframe	*s_wireframe)
{
	debug("Printing transformation...");
	printf("Scale: %f\n", s_wireframe->scale);
	ft_printf("Translate: %d %d\n", s_wireframe->translate.x, s_wireframe->translate.y);
	ft_printf("Rotate: %d %d %d\n\n", s_wireframe->rotate.x, s_wireframe->rotate.y, s_wireframe->rotate.z);
}

void	print_center(t_point center)
{
	ft_printf("Center: %d, %d, %d\n", center.x, center.y, center.z);
}

void	debug(char *str)
{
	static int i;

	if (str == NULL)
		ft_printf("Debug %d\n", i++);
	else
		ft_printf("Debug %d: %s\n", i++, str);
}
