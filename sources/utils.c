/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 16:13:11 by ohearn        #+#    #+#                 */
/*   Updated: 2023/04/07 23:24:08 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error_messages.h"
#include <errno.h>

void	copy_player_data(t_game *game)
{
	game->player.x = game->map.player[0];
	game->player.y = game->map.player[1];
	printf("player x:%i\nplayer y:%i\nmap player x:%i\nmap player y:%i\n", game->player.x, game->player.y, game->map.player[0], game->map.player[1]);
}

void	error(char *err_msg)
{
	ft_putstr_fd("Error\n", 2);
	if (errno == 0)
		ft_putendl_fd(err_msg, 2);
	else
		perror(err_msg);
	exit(EXIT_FAILURE);
}

void	*ft_realloc(void *ptr, size_t size)
{
	char	*ret;

	ret = ft_calloc2(1, size);
	if (ret == NULL)
		exit(EXIT_FAILURE);
	ft_memcpy(ret, ptr, size);
	free (ptr);
	return (ret);
}

int	file_check(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (i < 4 || ft_strncmp(&file[i - 4], ".ber", 4))
		return (-1);
	return (0);
}
