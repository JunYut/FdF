/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:12:52 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/16 12:04:30 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	load_map(t_frame *f, int argc, char *argv[]);
static void	init_mlx(t_frame *f);

int	main(int argc, char *argv[])
{
	t_frame	frame;

	load_map(&frame, argc, argv);
	init_mlx(&frame);
	ft_printf("Rendering...\n");
	mlx_loop_hook(frame.mlx.mlx, render_new_frame, &frame);
	mlx_loop(frame.mlx.mlx);
	return (0);
}

static void	load_map(t_frame *f, int argc, char *argv[])
{
	ft_printf("Parsing map...\n");
	f->map = parse_map(valid_arg(argc, argv[1]));
	valid_map(f->map);
	f->wireframe = init_wireframe(f->map);
}

static void	init_mlx(t_frame *f)
{
	t_img	*img;

	ft_printf("Initializing MinilibX components...\n");
	f->mlx.mlx = mlx_init();
	f->mlx.win = mlx_new_window(f->mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	img = &f->mlx.img;
	img->img = mlx_new_image(f->mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->offset = (WIN_HEIGHT * WIN_WIDTH * (img->bits_per_pixel / 8));
	mlx_hook(f->mlx.win, 17, 0, quit, f);
	mlx_hook(f->mlx.win, 2, 1L << 0, key_hook, f);
	mlx_key_hook(f->mlx.win, key_hook, f);
	f->redraw_flag = 1;
}
