/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:38:26 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/15 13:24:35 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	key_translate(int keycode, t_point *translate);
static void	key_rotate(int keycode, t_point *rotate);
static void	key_scale(int keycode, t_wireframe *wireframe);

int	quit(t_frame *f)
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
	if (keycode == KEY_ESC)
		quit(frame);
	frame->redraw_flag = 1;
	if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT
		|| keycode == KEY_RIGHT)
		key_translate(keycode, &frame->wireframe->translate);
	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A
		|| keycode == KEY_D || keycode == KEY_Q || keycode == KEY_E)
		key_rotate(keycode, &frame->wireframe->rotate);
	if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		key_scale(keycode, frame->wireframe);
	return (0);
}

static void	key_translate(int keycode, t_point *translate)
{
	if (keycode == KEY_UP)
	{
		translate->y += 10;
	}
	if (keycode == KEY_DOWN)
	{
		translate->y -= 10;
	}
	if (keycode == KEY_LEFT)
	{
		translate->x += 10;
	}
	if (keycode == KEY_RIGHT)
	{
		translate->x -= 10;
	}
}

static void	key_rotate(int keycode, t_point *rotate)
{
	if (keycode == KEY_W)
	{
		rotate->x += 5;
	}
	if (keycode == KEY_S)
	{
		rotate->x -= 5;
	}
	if (keycode == KEY_A)
	{
		rotate->y -= 5;
	}
	if (keycode == KEY_D)
	{
		rotate->y += 5;
	}
	if (keycode == KEY_Q)
	{
		rotate->z -= 5;
	}
	if (keycode == KEY_E)
	{
		rotate->z += 5;
	}
}

static void	key_scale(int keycode, t_wireframe *wireframe)
{
	if (keycode == KEY_PLUS)
	{
		wireframe->scale += 0.1;
	}
	if (keycode == KEY_MINUS)
	{
		if (wireframe->scale > 0.1)
			wireframe->scale -= 0.1;
	}
}
