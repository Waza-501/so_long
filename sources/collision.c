/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collision.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 14:44:18 by Owen          #+#    #+#                 */
/*   Updated: 2023/04/07 17:07:44 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error_messages.h"

static int  detect_north(t_game game)
{
    int     i;
    int     j;

    i = game.player.x + 1;
    j = game.player.y;
    if ((game.map.map[i][j]) == '1')
    {
        
        return (1);
    }
    if ((game.map.map[i][j]) == 'C')
    {
        game.collected++;

    }
    if ((game.map.map[i][j]) == 'E' && game.collected == game.map.collectibles)
    {
        mlx_close_window(game.mlx);
        mlx_terminate(game.mlx);
    }
    return (0);
}

static int  detect_east(t_game game)
{

}

static int  detect_south(t_game game)
{

}

static int  detect_west(t_game game)
{

}

int    detect_collision(t_game game)
{
    if (detect_north(game) == 1)
    {
        
    }

    return (0);
}