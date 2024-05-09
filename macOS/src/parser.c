/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:20:08 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/09 16:28:19 by we               ###   ########.fr       */
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
	((t_map *)(map->content))->rows = 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_lstadd_back(&map, ft_lstnew(parse_line(line)));
		++((t_map *)(map->content))->rows;
	}
	return (map);
}

t_map	*parse_line(char *line)
{
	t_map		*row;
	int			i;

	if (!line)
		return (NULL);
	row = (t_map *)c_malloc(sizeof(t_map));
	row->str = ft_strdup(line);
	row->split_nl = ft_split(row->str, '\n');
	row->split_space = ft_split(row->split_nl[0], ' ');
	row->columns = 0;
	while (row->split_space[row->columns])
		row->columns++;
	row->split_comma = (char ***)c_malloc(sizeof(char **) * row->columns);
	i = -1;
	while (++i < row->columns)
		row->split_comma[i] = ft_split(row->split_space[i], ',');
	free_split(row->split_nl);
	free_split(row->split_space);
	return (row);
}
