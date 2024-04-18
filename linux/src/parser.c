/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:20:08 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/04/16 15:24:49 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_map	*parse_map(int fd)
{
	t_map		*map;
	t_parser	parser;
	t_list		*current;
	int			i;

	map = (t_map *)c_malloc(sizeof(t_map));
	parser.list = ft_lstnew(0);
	current = parser.list;
	parser.str = get_next_line(fd);
	while (parser.str)
	{
		parser.split = ft_split(parser.str, ' ');
		parser.columns = count_words(parser.split);
		current = (int *)c_malloc(sizeof(int) * parser.columns);

		i = -1;
		while (parser.split[++i])
			((int *)current)[i] = ft_atoi(parser.split[i]);
		ft_lstadd_back(&parser.list, ft_lstnew(0));
		current = current->next;

		free_split(parser.split);
		c_free(parser.str);
		parser.str = get_next_line(fd);
	}
	return (map);
}
