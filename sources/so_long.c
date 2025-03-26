/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/04 09:28:43 by owen          #+#    #+#                 */
/*   Updated: 2025/03/26 17:11:05 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "err_codes.h"

int	map_type_valid(char *file)
{
	size_t	size;

	size = ft_strlen(file);
	if (size < 4 || ft_strncmp(&file[size - 4], ".ber", 4))
		exit_error(FILE_TYPE, NULL);
	return (0);
}

void	end_game(t_game *game)
{
	free_game(game);
}

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2)
		exit_error(INPUT_ERR, NULL);
	map_type_valid(argv[1]);
	game = init_structs();
	prepare_map(&game.map, argv[1], &game);
	return (0);
	start_game(&game);
	end_game(&game);
	return (0);
}
