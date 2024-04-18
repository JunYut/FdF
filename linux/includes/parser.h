/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 08:55:17 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/04/16 15:12:31 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "FdF.h"

typedef struct s_parser
{
	char	*str;
	char	**split;
	int		columns;
	t_list	*list;
}	t_parser;

#endif
