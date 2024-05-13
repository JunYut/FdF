/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:52:13 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/13 18:26:23 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include "FdF.h"

void	free_wireframe(t_wireframe *wireframe);
void	free_map(void *map_void);
void	free_split(char **split);
void	c_free(void *ptr);
void	*c_malloc(size_t size);

#endif
