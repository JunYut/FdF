/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   euler.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: we <we@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:16:11 by we                #+#    #+#             */
/*   Updated: 2024/05/16 12:19:51 by we               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EULER_H
# define EULER_H

# include "FdF.h"

typedef struct s_euler
{
	float	x[2];
	float	y[2];
	float	z[2];
	float	yx[2];
	float	zx[2];
	float	xy[2];
	float	zy[2];
}	t_euler;

#endif