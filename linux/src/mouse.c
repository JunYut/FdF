# include "struct.h"

int mouse_hook(int button, int x, int y, t_mlx *mlx)
{
	printf("Mouse button %d at %d, %d\n", button, x, y);
	(void)mlx;
	return (0);
}
