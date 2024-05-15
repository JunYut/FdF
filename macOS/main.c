/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:12:52 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/15 09:32:31 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	main(int argc, char *argv[])
{
	t_frame frame;
	int		fd;

	ft_printf("Parsing map...\n");
	fd = valid_arg(argc, argv[1]);
	frame.map = parse_map(fd);
	valid_map(frame.map);

	// Initialize the mlx and create a window
	ft_printf("Initializing system...\n");
	frame.mlx.mlx = mlx_init();
	frame.mlx.win = mlx_new_window(frame.mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
	frame.wireframe = init_wireframe(frame.map);
	frame.redraw_flag = 1;

	// Create an image
	frame.mlx.img.img = mlx_new_image(frame.mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	// newimg->buffer = malloc(UNIQ_BPP*width*height);

	// printf("Image addr: %p\n", (void *)frame.mlx.img.img);	// Debug
	frame.mlx.img.addr = mlx_get_data_addr(frame.mlx.img.img, &frame.mlx.img.bits_per_pixel, &frame.mlx.img.line_length, &frame.mlx.img.endian);
	// printf("Addr: %p\n", (void *)frame.mlx.img.addr);	// Debug
	frame.mlx.img.offset = (WIN_HEIGHT * WIN_WIDTH * (frame.mlx.img.bits_per_pixel / 8));
	// printf("Offset: %d\n", frame.mlx.img.offset);	// Debug

	// Set the loop hook and the key hook
	ft_printf("Rendering...\n");
	mlx_loop_hook(frame.mlx.mlx, render_new_frame, &frame);
	mlx_hook(frame.mlx.win, 17, 0, quit, &frame);
	mlx_hook(frame.mlx.win, 2, 1L<<0, key_hook, &frame);
	mlx_key_hook(frame.mlx.win, key_hook, &frame);

	// Loop
	mlx_loop(frame.mlx.mlx);

	return (0);
}
