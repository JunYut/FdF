/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:20:08 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/04/16 09:47:37 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_map	*parse_map(int fd)
{
	char 	*str;
	char	**split;
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	str = get_next_line(fd);
	while (str)
	{
		split = ft_split(str, ' ');
		c_free(str);
		str = get_next_line(fd);
	}
}
