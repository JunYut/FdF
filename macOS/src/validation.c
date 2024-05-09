/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:19:49 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/09 16:18:31 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	valid_map(t_list *map)
{
	t_list	*current;
	t_map	*tmp;
	int		columns;

	current = map;
	tmp = (t_map *)(map->content);
	columns = tmp->columns;
	while (current)
	{
		// Check if the number of columns is the same
		if (tmp->columns != columns)
		{
			ft_putstr_fd("Error: invalid columns\n", 2);
			ft_lstclear(&map, free_line);
			exit(1);
		}
		current = current->next;
		if (current)
			tmp = (t_map *)(current->content);
	}
}

/**
 * @brief Check if the argument count is correct and if file is valid
 * @param argc argument count
 * @param file argv[1]
 * @return The valid file's file descriptor
*/
int	valid_arg(int argc, char *file)
{
	int	fd;

	if (argc != 2)
	{
		ft_putstr_fd("Error: wrong argument count\n", 2);
		exit(1);
	}
	fd = valid_file(file);
	if (fd == -1)
	{
		exit(1);
	}
	return (fd);
}

int	valid_file(char *filename)
{
	int	len;
	int	fd;

	len = ft_strlen(filename);
	if (len < 5 || ft_strncmp(&filename[len - 4], ".fdf", 4))
	{
		ft_putstr_fd("Usage: ./FdF <file.fdf>\n", 2);
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		return (-1);
	}
	return (fd);
}
