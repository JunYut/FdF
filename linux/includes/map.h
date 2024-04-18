/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:07:38 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/04/17 09:07:58 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "FdF.h"

typedef struct s_map
{
	int		***map;
	int		width;
	int		height;
	int		z_min;
	int		z_max;
}	t_map;

#endif
