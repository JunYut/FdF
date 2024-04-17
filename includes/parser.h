/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 08:55:17 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/04/17 09:38:24 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "FdF.h"

typedef struct s_line
{
	char	*str;
	char	**split;
	int		columns;
}	t_line;

t_line	*parse_line(char *line);

#endif
