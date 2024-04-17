/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:45:26 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/04/17 14:29:32 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	free_line(void *line_void)
{
	t_line	*line;

	line = (t_line *)line_void;
	if (line->str)
		c_free(line->str);
	if (line->split_nl)
		free_split(line->split_nl);
	if (line->split_space)
		free_split(line->split_space);
	c_free(line);
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
	void	*ptr;

	ptr = (void *)malloc(size);
	if (!ptr)
		return (NULL);
	return (ptr);
}
