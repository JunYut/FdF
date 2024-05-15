/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:10:14 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/05/15 10:10:32 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

void	debug(char *str)
{
	static int	i;

	if (str == NULL)
		ft_printf("Debug %d\n", i++);
	else
		ft_printf("Debug %d: %s\n", i++, str);
}
