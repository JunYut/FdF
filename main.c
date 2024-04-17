/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:12:52 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/04/17 13:15:18 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	main(int argc, char *argv[])
{
	t_list	*map;
	int		fd;

	fd = valid_arg(argc, argv[1]);
	map = parse_map(fd);
	// valid_map(map);
	
	// Debug

	int i = 1;
	t_list	*current = map;
	while (current)
	{
		t_line	*line = (t_line *)(current->content);
		ft_printf("words[%d]: %d\n", i++, line->columns);
		for (int i = 0; i < line->columns; i++)
		{
			ft_printf("[%s]", line->split[i]);
			ft_putstr_fd(" ", 1);
		}
		ft_putstr_fd("\n", 1);
		current = current->next;
	}

}
