/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/04 09:28:43 by owen          #+#    #+#                 */
/*   Updated: 2025/03/13 16:48:52 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "err_codes.h"
#include <errno.h>
#include <fcntl.h>

void	exit_error(char	*error_code)
{
	ft_putendl_fd("ERROR", 2);
	if (errno == 0)
		ft_putendl_fd(error_code, 2);
	else
		perror(error_code);
	exit(-1);
}

int	map_type_valid(char *file)
{
	size_t	size;

	size = ft_strlen(file);
	if (size < 4 || ft_strncmp(&file[size - 4], ".ber", 4))
		exit_error(FILE_TYPE);
	return (0);
}

void	copy_map(t_map map, char *filename, int fd)
{
	int		idx;
	size_t	size;

	size = 0;
	idx = 0;
	(void)filename;
	map.map = ft_calloc(sizeof(char *), size + 1);
	if (!map.map[idx])
		exit_error(MEM_ERROR);
	while ((map.map[idx] = get_next_line(fd)) != NULL)
	{
		size = ft_strlen(map.map[idx]);
		if (map.map[idx][size - 1] == '\n')
			map.map[idx][size - 1] = '\0';
		idx++;
		map.map = ft_realloc(map.map, sizeof(char *), idx);
	}
}

void	check_rectangle(char **copy)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while(copy[x])
	{
		while(copy[x][y])
		{
			if (x == 0)
			y++;
		}
		x++;
	}
}

void	validate_map(t_map map)
{
	char	**copy;

	copy = map.map;
	check_rectangle(copy);
	//check_borders(copy);
	//check_targets(copy);
}

void	prepare_map(t_map map, char *filename)
{
	int		fd;
	//int		i;
	
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_error(FD_ERROR);
	copy_map(map, filename, fd);
	validate_map(map);
}

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2)
		exit_error(INPUT_ERR);
	map_type_valid(argv[1]);
	game = init_structs();
	prepare_map(game.map, argv[1]);
	return (0);
}
