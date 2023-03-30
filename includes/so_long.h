/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 14:07:17 by ohearn        #+#    #+#                 */
/*   Updated: 2023/03/30 13:43:15 by Owen          ########   odam.nl         */
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
	int		player[2];
	int		exit[2];
	int		collectibles;
	int		collected;
}					t_map;

/*struct to store general data*/
typedef struct s_data
{
	int			track_p;
	int			track_c;
	int			track_e;
}					t_data;

typedef struct s_game
{
	int			wi;
	int			he;
	mlx_t		*mlx;
	t_map		*map;
}					t_game;

/*map related functions*/
int			file_check(char *file);
void		open_map(char *path, t_map *map);
void		validate_map(t_map *map, t_data *data);
int			valid_char(char c);
void		count_char(t_map *map, t_data *data, int xi, int yi);
void		check_solvable(t_map *map, t_data *data);

/*utils*/
void		error(char *err_msg);
void		*ft_realloc(void *ptr, size_t size);

/*test functions*/
int			test_mlx(t_game *game);

#endif