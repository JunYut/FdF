# include "wireframe.h"

// Use after projecting the wireframe, before offsetting the projection
void	scale(t_wireframe *wireframe, float factor)
{
	int	i;

	i = -1;
	while (++i < wireframe->edges_count)
	{
		wireframe->projection[i].start.x *= factor;
		wireframe->projection[i].start.y *= factor;
		wireframe->projection[i].end.x *= factor;
		wireframe->projection[i].end.y *= factor;
	}
}

// Use after offsetting the projection
void	translate(t_wireframe *wireframe, int x, int y)
{
	int	i;

	i = -1;
	while (++i < wireframe->edges_count)
	{
		wireframe->projection[i].start.x += x;
		wireframe->projection[i].start.y += x;
		wireframe->projection[i].end.x += x;
		wireframe->projection[i].end.y += x;
	}
}

void rotate(t_wireframe *wireframe, float x, float y, float z)
{
	int i;
	float tmp;

	// Convert degrees to radians
	x = x * M_PI / 180;
	y = y * M_PI / 180;
	z = z * M_PI / 180;

	for (i = 0; i < wireframe->vertices_count; i++)
	{
		// Rotate around x-axis
		tmp = wireframe->vertices[i].y;
		wireframe->vertices[i].y = tmp * cos(x) - wireframe->vertices[i].z * sin(x);
		wireframe->vertices[i].z = tmp * sin(x) + wireframe->vertices[i].z * cos(x);

		// Rotate around y-axis
		tmp = wireframe->vertices[i].x;
		wireframe->vertices[i].x = tmp * cos(y) + wireframe->vertices[i].z * sin(y);
		wireframe->vertices[i].z = -tmp * sin(y) + wireframe->vertices[i].z * cos(y);

		// Rotate around z-axis
		tmp = wireframe->vertices[i].x;
		wireframe->vertices[i].x = tmp * cos(z) - wireframe->vertices[i].y * sin(z);
		wireframe->vertices[i].y = tmp * sin(z) + wireframe->vertices[i].y * cos(z);
	}
}
