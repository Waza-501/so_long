/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 14:07:17 by ohearn        #+#    #+#                 */
/*   Updated: 2023/02/10 18:24:07 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/libft/header/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <math.h>

/*map_check*/
int			file_check(char *file);

/*utils*/
void		error(char *err_msg);

#endif