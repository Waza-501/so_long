/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 14:07:17 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/12 15:24:02 by ohearn        ########   odam.nl         */
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

/*struct to store player data*/
typedef struct s_player
{
	int				x;
	int				y;
	mlx_image_t		*img;
	mlx_texture_t	*pmodel;
}					t_player;

/*structs to store map related data*/
typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	int		player[2];
	int		exit[2];
	int		collectibles;
}					t_map;

typedef struct s_world
{
	mlx_t			*mlx;
	mlx_image_t		*wrld;
	mlx_texture_t	*water;
	mlx_texture_t	*grass;
	mlx_texture_t	*collectible;
	mlx_texture_t	*exit;
}					t_world;

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
	int			collected;
	int			mvmnt;
	int			counter;
	int			allow_leave;
	mlx_t		*mlx;
	t_map		map;
	t_world		world;
	t_player	player;
}					t_game;

/*initiate structs*/

t_game			init_game(void);
t_map			init_map(void);
t_world			init_world(void);
t_player		init_player(void);

/*map related functions*/
int				file_check(char *file);
void			open_map(char *path, t_map *map);
void			validate_map(t_map *map, t_data *data);
int				valid_char(char c);
void			count_char(t_map *map, t_data *data, int xi, int yi);
void			check_solvable(t_map *map, t_data *data);

/*collision*/
void			detect_collision(t_game *game, int x, int y);

/*utils*/
void			error(char *err_msg);
void			*ft_realloc(void *ptr, size_t size);
void			ft_keyhook(mlx_key_data_t keydata, void *input);
void			build_game(t_game game);
void			copy_player_data(t_game *game);

#endif