# include "FdF.h"

int quit(t_frame *f)
{
	ft_printf("Exiting...\n");
	ft_lstclear(&f->map, free_map);
	free_wireframe(f->wireframe);
	mlx_destroy_window(f->mlx.mlx, f->mlx.win);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_frame *frame)
{
	// ft_printf("Keycode: %d\n", keycode);
	if (keycode == KEY_ESC)
		quit(frame);
	frame->redraw_flag = 1;
	if (keycode == KEY_UP)
	{
		frame->wireframe->translate.y += 10;
	}
	if (keycode == KEY_DOWN)
	{
		frame->wireframe->translate.y -= 10;
	}
	if (keycode == KEY_LEFT)
	{
		frame->wireframe->translate.x += 10;
	}
	if (keycode == KEY_RIGHT)
	{
		frame->wireframe->translate.x -= 10;
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
