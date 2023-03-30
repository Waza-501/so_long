/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Owen <Owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/30 13:16:58 by Owen          #+#    #+#                 */
/*   Updated: 2023/03/30 13:50:15 by Owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "error_messages.h"
#include <stdbool.h>
# define HEIGHT 512
# define WIDTH	512

static mlx_image_t *image;

void	escape_hook(void *param)
{
	mlx_t	*mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int	test_mlx(t_game *game)
{
	mlx_t	*mlx;

	if (!(mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	write(1, "checkpoint 2\n", 13);
	if (!(image = mlx_new_image(mlx, 128, 128)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (!(mlx_image_to_window(mlx, image, 0, 0) == -1))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	write(1, "checkpoint 3\n", 13);
	mlx_loop_hook(mlx, escape_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
	}