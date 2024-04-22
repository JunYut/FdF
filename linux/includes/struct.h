# pragma once

# include "c_libft.h"
# include "mlx_int.h"
# include "mlx.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}		t_data;