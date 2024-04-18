/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 08:55:17 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/04/17 13:32:10 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "FdF.h"

typedef struct s_line
{
	char	*str;
	char	**split_nl;
	char	**split_space;
	int		columns;
}	t_line;

t_line	*parse_line(char *line);

#endif
