/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:00:41 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/15 10:01:30 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

int	render_new_frame(t_frame *frame)
{
	t_wireframe	*w;
	t_mlx		*m;

	w = frame->wireframe;
	m = &frame->mlx;
	if (frame->redraw_flag == 1)
	{
		mlx_clear_window(m->mlx, m->win);
		ft_bzero(m->img.addr, m->img.offset);
		offset_origin(w);
		rotate(w, w->rotate.x, w->rotate.y, w->rotate.z);
		c_projector(w);
		scale(w, w->scale);
		offset_center(w);
		translate(w, w->translate.x, w->translate.y);
		draw_wireframe(m, w);
		mlx_put_image_to_window(m->mlx, m->win, m->img.img, 0, 0);
		frame->redraw_flag = 0;
	}
	return (0);
}

void	render_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		byte_offset;

	byte_offset = (y * img->line_length + x * (img->bits_per_pixel / 8));
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = img->addr + byte_offset;
		*(unsigned int *)dst = color;
	}
}
