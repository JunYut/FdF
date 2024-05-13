/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:07:38 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/13 15:08:47 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "FdF.h"

typedef struct s_map
{
	char	***split_comma;
	char	**split_space;
	char	**split_nl;
	char	*str;
	int		rows;
	int		columns;
}	t_map;

void	valid_map(t_list *map);
int		valid_arg(int argc, char *file);
int		valid_file(char *file);
t_list	*parse_map(int fd);
t_map	*parse_line(char *line);


#endif
