/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:45:26 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/14 11:26:29 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	free_wireframe(t_wireframe *wireframe)
{
	c_free(wireframe->projection);
	c_free(wireframe->rotated);
	c_free(wireframe->edges);
	c_free(wireframe->vertices);
	c_free(wireframe);
}

// Used with ft_lstclear
void	free_map(void *map_void)
{
	t_map	*map;
	int		i;

	map = (t_map *)map_void;
	c_free(map->str);
	free_split(map->split_nl);
	free_split(map->split_space);
	i = -1;
	while (++i < map->columns)
		free_split(map->split_comma[i]);
	c_free(map);
	(void)i;
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		c_free(split[i]);
	c_free(split);
}

void	c_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	*c_malloc(size_t size)
{
	static int	count;
	static int	total;
	void	*ptr;

	++count;
	total += size;
	// ft_printf("Malloc count: %d, size: %d, total: %d\n", count, size, total);
	ptr = (void *)malloc(size);
	if (!ptr)
		return (NULL);
	return (ptr);
}
