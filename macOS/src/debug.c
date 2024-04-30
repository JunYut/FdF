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
