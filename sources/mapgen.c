/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mapgen.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 14:28:39 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/02 15:48:19 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error_messages.h"

t_map init_map(void)
{
	t_map	to_return;

	to_return.collectibles = 0;
	to_return.exit[0] = 0;
	to_return.exit[1] = 0;
	to_return.map = NULL;
	to_return.player[0]= 0;
	to_return.player[1]= 0;
	to_return.x = 0;
	to_return.y = 0;
	return (to_return);
}

void	generate_map(t_world *world, t_map *map)
{
	
}