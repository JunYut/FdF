# include "wireframe.h"

int quit(t_mlx *mlx)
{
	ft_printf("Exiting...\n");
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_frame *frame)
{
	// ft_printf("Keycode: %d\n", keycode);
	if (keycode == KEY_ESC)
		quit(&frame->mlx);
	frame->redraw_flag = 1;
	if (keycode == KEY_UP)
	{
		frame->wireframe->translate.y -= 10;
	}
	if (keycode == KEY_DOWN)
	{
		frame->wireframe->translate.y += 10;
	}
	if (keycode == KEY_LEFT)
	{
		frame->wireframe->translate.x -= 10;
	}
	if (keycode == KEY_RIGHT)
	{
		frame->wireframe->translate.x += 10;
	}
	if (keycode == KEY_W)
	{
		frame->wireframe->rotate.x += 10;
	}
	if (keycode == KEY_S)
	{
		frame->wireframe->rotate.x -= 10;
	}
	if (keycode == KEY_A)
	{
		frame->wireframe->rotate.y -= 10;
	}
	if (keycode == KEY_D)
	{
		frame->wireframe->rotate.y += 10;
	}
	if (keycode == KEY_Q)
	{
		frame->wireframe->rotate.z -= 10;
	}
	if (keycode == KEY_E)
	{
		frame->wireframe->rotate.z += 10;
	}
	if (keycode == KEY_PLUS)
	{
		frame->wireframe->scale += 0.1;
	}
	if (keycode == KEY_MINUS)
	{
		if (frame->wireframe->scale > 0.1)
			frame->wireframe->scale -= 0.1;
	}
	return (0);
}
