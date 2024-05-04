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
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		frame->redraw_flag = 1;
		frame->wireframe->translate.y -= 10;
	}
	if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		frame->redraw_flag = 1;
		frame->wireframe->translate.y += 10;
	}
	if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		frame->redraw_flag = 1;
		frame->wireframe->translate.x -= 10;
	}
	if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		frame->redraw_flag = 1;
		frame->wireframe->translate.x += 10;
	}
	if (keycode == KEY_PLUS)
	{
		frame->redraw_flag = 1;
		frame->wireframe->scale += 0.1;
	}
	if (keycode == KEY_MINUS)
	{
		frame->redraw_flag = 1;
		frame->wireframe->scale -= 0.1;
	}
	return (0);
}
