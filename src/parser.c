/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:20:08 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/04/16 11:04:12 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_map	*parse_map(int fd)
{
	t_parser	parser;
	t_map		*map;

	map = (t_map *)c_malloc(sizeof(t_map));
	parser.str = get_next_line(fd);
	while (parser.str)
	{
		parser.split = ft_split(parser.str, ' ');
		free_split(parser.split);
		c_free(parser.str);
		parser.str = get_next_line(fd);
	}
	return (map);
}
