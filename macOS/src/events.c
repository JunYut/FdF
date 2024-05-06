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
	printf("Keycode: %d\n", keycode);	// Debug
	if (keycode == KEY_ESC)
		quit(&frame->mlx);
	frame->redraw_flag = 1;
	if (keycode == KEY_UP)
	{
		frame->wireframe->translate.y += 10;
		printf("Translate: %d %d\n", frame->wireframe->translate.x, frame->wireframe->translate.y);	// Debug
	}
	if (keycode == KEY_DOWN)
	{
		frame->wireframe->translate.y -= 10;
		printf("Translate: %d %d\n", frame->wireframe->translate.x, frame->wireframe->translate.y);	// Debug
	}
	if (keycode == KEY_LEFT)
	{
		frame->wireframe->translate.x -= 10;
		printf("Translate: %d %d\n", frame->wireframe->translate.x, frame->wireframe->translate.y);	// Debug
	}
	if (keycode == KEY_RIGHT)
	{
		frame->wireframe->translate.x += 10;
		printf("Translate: %d %d\n", frame->wireframe->translate.x, frame->wireframe->translate.y);	// Debug
	}
	if (keycode == KEY_W)
	{
		if (frame->wireframe->rotate.x >= -360 && frame->wireframe->rotate.x < 360)
		{
			frame->wireframe->rotate.x += 10;
			printf("Rotate: %d %d %d\n", frame->wireframe->rotate.x, frame->wireframe->rotate.y, frame->wireframe->rotate.z);	// Debug
		}
	}
	if (keycode == KEY_S)
	{
		if (frame->wireframe->rotate.x > -360 && frame->wireframe->rotate.x <= 360)
		{
			frame->wireframe->rotate.x -= 10;
			printf("Rotate: %d %d %d\n", frame->wireframe->rotate.x, frame->wireframe->rotate.y, frame->wireframe->rotate.z);	// Debug
		}
	}
	if (keycode == KEY_A)
	{
		if (frame->wireframe->rotate.y > -360 && frame->wireframe->rotate.y <= 360)
			frame->wireframe->rotate.y -= 10;
		printf("Rotate: %d %d %d\n", frame->wireframe->rotate.x, frame->wireframe->rotate.y, frame->wireframe->rotate.z);	// Debug
	}
	if (keycode == KEY_D)
	{
		if (frame->wireframe->rotate.y >= -360 && frame->wireframe->rotate.y < 360)
			frame->wireframe->rotate.y += 10;
		printf("Rotate: %d %d %d\n", frame->wireframe->rotate.x, frame->wireframe->rotate.y, frame->wireframe->rotate.z);	// Debug
	}
	if (keycode == KEY_Q)
	{
		if (frame->wireframe->rotate.z > -360 && frame->wireframe->rotate.z <= 360)
			frame->wireframe->rotate.z -= 10;
		printf("Rotate: %d %d %d\n", frame->wireframe->rotate.x, frame->wireframe->rotate.y, frame->wireframe->rotate.z);	// Debug
	}
	if (keycode == KEY_E)
	{
		if (frame->wireframe->rotate.z >= -360 && frame->wireframe->rotate.z < 360)
			frame->wireframe->rotate.z += 10;
		printf("Rotate: %d %d %d\n", frame->wireframe->rotate.x, frame->wireframe->rotate.y, frame->wireframe->rotate.z);	// Debug
	}
	if (keycode == KEY_PLUS)
	{
		frame->wireframe->scale += 0.1;
		printf("Scale: %f\n", frame->wireframe->scale);	// Debug
	}
	if (keycode == KEY_MINUS)
	{
		if (frame->wireframe->scale > 0.1)
			frame->wireframe->scale -= 0.1;
		printf("Scale: %f\n", frame->wireframe->scale);	// Debug
	}
	return (0);
}
