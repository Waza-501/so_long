/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/03 10:34:29 by owen          #+#    #+#                 */
/*   Updated: 2025/03/13 16:48:58 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libraries/libft/libft.h"

typedef struct s_player_data
{
	int		player_x;
	int		player_y;
}			t_player_data;

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	int		max_x;
	int		max_y;
}			t_map;

typedef struct s_game
{
	mlx_t			*mlx;
	t_player_data	*player;
	t_map			map;
	int				width;
	int				height;
	
}			t_game;

void		copy_map(t_map map, char *filename, int fd);
t_map		init_map(void);
t_game		init_structs(void);
int			tester(int	num);

#endif