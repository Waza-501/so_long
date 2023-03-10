/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 14:07:17 by ohearn        #+#    #+#                 */
/*   Updated: 2023/03/07 16:22:56 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/libft/header/libft.h"
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
	

	t_map	*map;
}					t_data;

/*map_check*/
int			file_check(char *file);

/*utils*/
void		error(char *err_msg);

#endif