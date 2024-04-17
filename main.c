/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:12:52 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/04/17 10:08:18 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	main(int argc, char *argv[])
{
	t_map	*map;
	int		fd;

	fd = valid_arg(argc, argv[1]);
	map = parse_map(fd);
}
