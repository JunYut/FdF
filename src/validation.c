/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjun-yu <tjun-yu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:19:49 by tjun-yu           #+#    #+#             */
/*   Updated: 2024/04/15 11:11:03 by tjun-yu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static int	valid_file(char *filename);

/**
 * @brief Check if the argument count is correct and if file is valid
 * @param argc argument count
 * @param argv argument vector
 * @return a valid file's file descriptor
*/
int	validation(int argc, char *argv[])
{
	int	fd;

	if (argc != 2)
	{
		ft_putstr_fd("Error: wrong argument count\n", 2);
		exit(1);
	}
	fd = valid_file(argv[1]);
	if (fd == -1)
	{
		exit(1);
	}
	return (fd);
}

static int	valid_file(char *filename)
{
	int	len;
	int	fd;

	len = ft_strlen(filename);
	if (len < 5 || ft_strncmp(&filename[len - 4], ".fdf", 4))
	{
		ft_putstr_fd("Error: wrong file extension\n", 2);
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: failed to open file\n", 2);
		return (-1);
	}
	return (fd);
}
