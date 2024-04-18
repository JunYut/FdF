/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:19:41 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/04/16 14:12:34 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# include "c_libft.h"
# include "mlx.h"
# include "utils.h"
# include "memory.h"
# include "parser.h"
# include "line.h"

typedef struct s_parser	t_parser;
typedef struct s_line	t_line;

typedef struct s_map
{
	int		**map;
	int		width;
	int		height;
	int		z_min;
	int		z_max;
	int		z_range;
}	t_map;

int		validation(int argc, char *file);
t_map	*parse_map(int fd);

#endif
