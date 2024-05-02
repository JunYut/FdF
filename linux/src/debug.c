# include "wireframe.h"

void	print_wireframe(t_wireframe *wireframe)
{
	for (int i = 0; i < wireframe->edges_count; i++)
	{
		ft_printf("Edge %d\n", i);
		ft_printf("Start: %d %d %d\n", wireframe->edges[i].start.x, wireframe->edges[i].start.y, wireframe->edges[i].start.z);
		ft_printf("End: %d %d %d\n", wireframe->edges[i].end.x, wireframe->edges[i].end.y, wireframe->edges[i].end.z);
		ft_printf("\n");
	}
}

void	print_projection(t_wireframe *wireframe)
{
	for (int i = 0; i < wireframe->edges_count; i++)
	{
		ft_printf("Projection %d\n", i);
		ft_printf("Start: %d %d %d\n", wireframe->projection[i].start.x, wireframe->projection[i].start.y, wireframe->projection[i].start.z);
		ft_printf("End: %d %d %d\n", wireframe->projection[i].end.x, wireframe->projection[i].end.y, wireframe->projection[i].end.z);
		ft_printf("\n");
	}
}

void	print_vertices(t_wireframe *wireframe)
{
	for (int i = 0; i < wireframe->vertices_count; i++)
	{
		ft_printf("Vertex %d\n", i);
		ft_printf("Coordinates: %d %d %d\n", wireframe->vertices[i].x, wireframe->vertices[i].y, wireframe->vertices[i].z);
		ft_printf("\n");
	}
}
