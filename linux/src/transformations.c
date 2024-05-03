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
void	translate(t_wireframe *wireframe, int x, int y, int z)
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

void	rotate(t_wireframe *wireframe, int x, int y, int z)
{

}
