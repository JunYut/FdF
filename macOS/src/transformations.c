# include "wireframe.h"

// Use after projecting the wireframe, before offsetting the projection
void	scale(t_wireframe *wireframe, float factor)
{
	// debug("Scaling wireframe...");
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
	// debug("Translating wireframe...");
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
	// debug("Rotating wireframe...");
	int i;

	// Convert degrees to radians
	x = x * M_PI / 180;
	y = y * M_PI / 180;
	z = z * M_PI / 180;

	i = -1;
	while (++i < wireframe->edges_count)
	{
		float start_x = wireframe->edges[i].start.x;
		float start_y = wireframe->edges[i].start.y;
		float start_z = wireframe->edges[i].start.z;

		float end_x = wireframe->edges[i].end.x;
		float end_y = wireframe->edges[i].end.y;
		float end_z = wireframe->edges[i].end.z;

		// Rotate around x-axis
		float start_y_x = start_y * cos(x) - start_z * sin(x);
		float start_z_x = start_y * sin(x) + start_z * cos(x);
		float end_y_x = end_y * cos(x) - end_z * sin(x);
		float end_z_x = end_y * sin(x) + end_z * cos(x);

		// Rotate around y-axis
		float start_x_y = start_x * cos(y) + start_z_x * sin(y);
		float start_z_y = -start_x * sin(y) + start_z_x * cos(y);
		float end_x_y = end_x * cos(y) + end_z_x * sin(y);
		float end_z_y = -end_x * sin(y) + end_z_x * cos(y);

		// Rotate around z-axis
		wireframe->rotated[i].start.x = start_x_y * cos(z) - start_y_x * sin(z);
		wireframe->rotated[i].start.y = start_x_y * sin(z) + start_y_x * cos(z);
		wireframe->rotated[i].start.z = start_z_y;
		wireframe->rotated[i].end.x = end_x_y * cos(z) - end_y_x * sin(z);
		wireframe->rotated[i].end.y = end_x_y * sin(z) + end_y_x * cos(z);
		wireframe->rotated[i].end.z = end_z_y;
	}
}
