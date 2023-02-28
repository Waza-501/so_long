/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 14:00:26 by ohearn        #+#    #+#                 */
/*   Updated: 2023/02/23 15:16:08 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error_messages.h"

void	open_map(char *path, t_data *data)
{
	int		fd;
	int		i;
	int		bytes;
	char 	buffer[2];

	i = 0;
	bytes = 1;
	buffer[1] = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error(ERR_FD);
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes != 1)
			break;
		if (buffer[0] != '\n' && buffer[0] != '\0')
			data->map->map[i] = ft_strjoin(data->map->map[i], buffer);
		else
			i++;
	}
}
