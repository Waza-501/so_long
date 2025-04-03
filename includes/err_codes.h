/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   err_codes.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/04 15:18:28 by owen          #+#    #+#                 */
/*   Updated: 2025/04/03 15:24:16 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_CODES_H
# define ERR_CODES_H
# define INPUT_ERR		"Input error. Please use ./so_long <FILE.ber>."
# define FILE_TYPE		"There was an error reading the map. Please make sure\
 the map is a .ber file."
# define FD_ERROR		"File could not be opened. Make sure the file exists\
 and can be opened."
# define MEM_ERROR		"There was an issue allocating memory."
# define MAP_RECT		"Please make sure the map is a rectangle."
# define MAP_CHAR		"Invalid character found. The accepted characters are\
 0, 1, C, E, P."
# define MAP_WALLS		"The borders of the map need to be walls."
# define MAP_COL		"The map needs at least one collectible."
# define MAP_EXIT		"The map needs a single exit."
# define MAP_SPAWN		"The map needs a single spawn."
# define MAP_UNSOLVABLE	"The map needs to be solvable."
# define MLX_FAILED		"There was an issue with MLX. Please try again."
# define MLX_LOAD_FAIL	"There was an issue loading the PNG."
# define SOP			"a thing of no great value given or done as a concession\
 to appease someone whose main concerns or demands are not being met."
# define MLX_LOAD_TTI	"There was an issue converting a texture to an image."
#endif