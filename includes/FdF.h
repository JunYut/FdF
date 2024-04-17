/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:19:41 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/04/17 10:11:36 by tjun-yu          ###   ########.fr       */
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
# include "validation.h"
# include "memory.h"
# include "parser.h"

typedef struct s_parser	t_parser;
typedef struct s_line	t_line;
typedef struct s_map	t_map;
typedef struct s_point	t_point;

int		valid_arg(int argc, char *file);
void	valid_map(t_list *map);
t_list	*parse_map(int fd);
void	clean_up();

#endif
