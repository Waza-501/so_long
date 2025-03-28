/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/03 10:34:29 by owen          #+#    #+#                 */
/*   Updated: 2025/03/28 17:34:28 by owhearn       ########   odam.nl         */
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

# define SUCCESS 	0
# define FAILURE 	1
# define COLL_WALL	"The bunny can't swim so it's best to stay on the grass."
# define ENDGAME	"You've collected them all! Head for the exit."

typedef struct s_player_data
{
	int				player_x;
	int				player_y;
	int				collectibles;
	mlx_image_t		*player;
}					t_player_data;

typedef struct s_textures
{
	mlx_texture_t		*wall;
	mlx_texture_t		*floor;
	mlx_texture_t		*collec;
	mlx_texture_t		*exit;
	mlx_texture_t		*pmodel;
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
	t_map			copy;
	t_textures		*tex;
	mlx_image_t		*collectable;
	mlx_image_t		*counter;
	bool			endgame;
	int				moves;
}			t_game;

/*Movement.c*/
void			sl_move_up(t_game *game, int y, int x);
void			sl_move_left(t_game *game, int y, int x);
void			sl_move_down(t_game *game, int y, int x);
void			sl_move_right(t_game *game, int y, int x);

/**/
void			detect_col(t_game *game, int i_y, int i_x);
void			free_game(t_game *game);
void			update_counter(t_game *game);
void			free_textures(t_game *game);
void			ft_hooky(mlx_key_data_t key, void *input);
void			start_game(t_game *game);
void			solve_map(t_map *map, t_game *game);
void			check_rectangle(t_map *map, t_game *game);
void			validate_map(t_map *map, t_game *game);
void			pull_map_from_file(t_map *map, int fd, t_game *game, int lines);
void			prepare_map(t_map *map, char *filename, t_game *game);
t_player_data	*init_p_data(t_game *game, int i_y, int i_x);
t_map			init_map(void);
t_textures		*init_textures(t_game *game);
t_game			init_structs(void);
int				tester(int num);
void			free_map(t_map *map);
void			exit_error(char	*error_code, t_game *game);

#endif