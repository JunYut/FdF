/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:07:38 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/08 14:34:43 by tjun-yu          ###   ########.fr       */
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

typedef struct s_str
{
	char	*str;
	char	**split_nl;
	char	**split_space;
	char	***split_comma;
	int		rows;
	int		columns;
}	t_str;

void	valid_map(t_list *map);
int		valid_arg(int argc, char *file);
int		valid_file(char *file);
t_list	*parse_map(int fd);
t_str	*parse_line(char *line);


#endif
