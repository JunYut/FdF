#include "wireframe.h"

// Use after scaling
void	offset_center(t_wireframe *w)
{
	// debug("Offsetting w...");
	int i;

	update_center(w, w->projection, w->edges_count);
	i = -1;
	while (++i < w->edges_count)
	{
		w->projection[i].start.x += WIN_WIDTH / 2 - w->center.x;
		w->projection[i].start.y += WIN_HEIGHT / 2 - w->center.y;
		w->projection[i].end.x += WIN_WIDTH / 2 - w->center.x;
		w->projection[i].end.y += WIN_HEIGHT / 2 - w->center.y;
	}
}

// Use before rotating
void	offset_origin(t_wireframe *w)
{
	// debug("Offsetting center...");
	int i;

	update_center(w, w->edges, w->edges_count);
	i = -1;
	while (++i < w->edges_count)
	{
		w->edges[i].start.x -= w->center.x;
		w->edges[i].start.y -= w->center.y;
		w->edges[i].end.x -= w->center.x;
		w->edges[i].end.y -= w->center.y;
	}
	// print_edges(w->edges, w->edges_count);	// Debug
	// print_center(w->center);	// Debug
}
