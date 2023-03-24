/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 14:07:17 by ohearn        #+#    #+#                 */
/*   Updated: 2023/03/24 13:07:06 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/libft/header/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>

/*struct to store map related data*/
typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	int		collected;
}					t_map;

typedef struct s_data
{
	mlx_t		*mlx;
	t_map		*map;
}					t_data;

/*map related functions*/
int			file_check(char *file);
void		open_map(char *path, t_map *map);

/*utils*/
void		error(char *err_msg);
void		*ft_realloc(void *ptr, size_t size);

#endif