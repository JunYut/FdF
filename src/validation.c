/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:19:49 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/04/17 15:00:25 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	valid_map(t_list *map)
{
	t_list	*current;
	t_line	*tmp;
	int		columns;
	int		comma;
	int		i;

	current = map;
	tmp = (t_line *)(map->content);
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

		// Check if all characters are alnum, '-' or ','
		i = -1;
		while (tmp->split_nl[0][++i])
		{
			if (!ft_isalnum(tmp->split_nl[0][i])
			&& tmp->split_nl[0][i] != '-'
			&& tmp->split_nl[0][i] != ',')
			{
				ft_putstr_fd("Error: invalid characters\n", 2);
				ft_lstclear(&map, free_line);
				exit(1);
			}
		}

		// Check if the first character is a digit or '-' & if there are more than 1 comma
		comma = 0;
		i = -1;
		while (tmp->split_space[++i])
		{
			if (tmp->split_space[i][0] == ',')
				comma++;
			if (!ft_isdigit(tmp->split_space[i][0])
			&& tmp->split_space[i][0] != '-'
			|| comma > 1)
			{
				ft_putstr_fd("Error: invalid characters\n", 2);
				ft_lstclear(&map, free_line);
				exit(1);
			}
		}

		current = current->next;
		if (current)
			tmp = (t_line *)(current->content);
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
