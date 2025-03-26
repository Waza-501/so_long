/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/03 10:34:29 by owen          #+#    #+#                 */
/*   Updated: 2025/03/26 10:56:28 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libraries/libft/libft.h"

# define SUCCESS 0
# define FAILURE 1

typedef struct s_player_data
{
	int				player_x;
	int				player_y;
	int				collectibles;
	mlx_texture_t	*pmodel;
}					t_player_data;

typedef struct s_textures
{
	mlx_texture_t		*wall;
	mlx_texture_t		*floor;
	mlx_texture_t		*collec;
	mlx_texture_t		*exit;
	mlx_image_t			*world;
}						t_textures;

typedef struct s_map
{
	char	**map;
	int		p_spawn[2];
	int		e_spawn[2];
	size_t	max_x;
	size_t	max_y;
	int		token_c;
	int		token_e;
	int		token_p;
}			t_map;

typedef struct s_game
{
	mlx_t			*mlx;
	t_player_data	*player;
	t_map			map;
	t_textures		tex;
	mlx_image_t		*counter;
	int				moves;
	int				width;
	int				height;
}			t_game;


void		free_textures(t_game *game);
void		ft_hooky(mlx_key_data_t key, void *input);
void		start_game(t_game *game);
void		solve_map(t_map *map);
void		check_rectangle(t_map *map);
void		validate_map(t_map *map);
void		pull_map_from_file(t_map *map, int fd);
void		prepare_map(t_map *map, char *filename);
t_map		init_map(void);
t_game		init_structs(void);
int			tester(int num);
void		free_map(t_map *map);
void		exit_error(char	*error_code);

#endif