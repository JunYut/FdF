# include "wireframe.h"

// Use after projecting the wireframe, before offsetting the projection
void	scale(t_wireframe *wireframe, float factor)
{
	debug("Scaling wireframe...");
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
	debug("Translating wireframe...");
	int	i;

	i = -1;
	while (++i < wireframe->edges_count)
	{
		wireframe->projection[i].start.x += x;
		wireframe->projection[i].start.y += y;
		wireframe->projection[i].end.x += x;
		wireframe->projection[i].end.y += y;
	}
}

// Use before projecting the wireframe
void rotate(t_wireframe *wireframe, float x, float y, float z)
{
	debug("Rotating wireframe...");
	int i;
	float tmp;

	// Convert degrees to radians
	x = x * M_PI / 180;
	y = y * M_PI / 180;
	z = z * M_PI / 180;

	for (int i = 0; i < wireframe->edges_count; i++)
	{
		tmp = wireframe->edges[i].start.y;
		wireframe->rotated[i].start.y = tmp * cos(x) - wireframe->edges[i].start.z * sin(x);
		wireframe->rotated[i].start.z = tmp * sin(x) + wireframe->edges[i].start.z * cos(x);

		tmp = wireframe->edges[i].start.x;
		wireframe->rotated[i].start.x = tmp * cos(y) + wireframe->edges[i].start.z * sin(y);
		wireframe->rotated[i].start.z = -tmp * sin(y) + wireframe->edges[i].start.z * cos(y);

		tmp = wireframe->edges[i].start.x;
		wireframe->rotated[i].start.x = tmp * cos(z) - wireframe->edges[i].start.y * sin(z);
		wireframe->rotated[i].start.y = tmp * sin(z) + wireframe->edges[i].start.y * cos(z);

		tmp = wireframe->edges[i].end.y;
		wireframe->rotated[i].end.y = tmp * cos(x) - wireframe->edges[i].end.z * sin(x);
		wireframe->rotated[i].end.z = tmp * sin(x) + wireframe->edges[i].end.z * cos(x);

		tmp = wireframe->edges[i].end.x;
		wireframe->rotated[i].end.x = tmp * cos(y) + wireframe->edges[i].end.z * sin(y);
		wireframe->rotated[i].end.z = -tmp * sin(y) + wireframe->edges[i].end.z * cos(y);

		tmp = wireframe->edges[i].end.x;
		wireframe->rotated[i].end.x = tmp * cos(z) - wireframe->edges[i].end.y * sin(z);
		wireframe->rotated[i].end.y = tmp * sin(z) + wireframe->edges[i].end.y * cos(z);
	}
}
