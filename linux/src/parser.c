/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:20:08 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/04/17 13:48:08 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_list	*parse_map(int fd)
{
	t_list	*map;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	map = ft_lstnew(parse_line(line));
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_lstadd_back(&map, ft_lstnew(parse_line(line)));
	}
	return (map);
}

t_line	*parse_line(char *line)
{
	t_line		*row;

	if (!line)
		return (NULL);
	row = (t_line *)c_malloc(sizeof(t_line));
	row->str = ft_strdup(line);
	row->split_nl = ft_split(row->str, '\n');
	row->split_space = ft_split(row->split_nl[0], ' ');
	row->columns = 0;
	while (row->split_space[row->columns])
		row->columns++;
	return (row);
}
