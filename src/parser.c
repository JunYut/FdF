/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:20:08 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/04/17 10:01:32 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_list	*parse_map(int fd)
{
	t_list	*lines;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	lines = ft_lstnew(parse_line(line));
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_lstadd_back(&lines, ft_lstnew(parse_line(line)));
	}
	return (lines);
}

t_line	*parse_line(char *line)
{
	t_line		*row;

	if (!line)
		return (NULL);
	row = (t_line *)c_malloc(sizeof(t_line));
	row->str = ft_strdup(line);
	row->split = ft_split(row->str, ' ');
	row->columns = 0;
	while (row->split[row->columns])
		row->columns++;
	return (row);
}
