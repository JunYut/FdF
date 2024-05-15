/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:52:13 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/14 08:51:19 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include "FdF.h"

typedef struct s_wireframe	t_wireframe;

void	free_wireframe(t_wireframe *wireframe);
void	free_map(void *map_void);
void	free_split(char **split);
void	c_free(void *ptr);
void	*c_malloc(size_t size);

#endif
