# include "struct.h"

int key_hook(int keycode, t_mlx *mlx)
{
	printf("Keycode: %d\n", keycode);
	switch (keycode)
	{
	case ESC:	quit(mlx);
		break;

	case UP:
	case W:	up();
		break;

	case DOWN:
	case S:	down();
		break;

	case LEFT:
	case A:	left();
		break;

	case RIGHT:
	case D:	right();
		break;

	default:
		break;
	}
	return 0;
}

int quit(t_mlx *mlx)
{
	printf("Quiting...\n");
	mlx_destroy_image(mlx->mlx,mlx->img.img);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}
int up(void)
{
	printf("up\n");
	return (0);
}
int down(void)
{
	printf("down\n");
	return (0);
}
int left(void)
{
	printf("left\n");
	return (0);
}
int right(void)
{
	printf("right\n");
	return (0);
}
