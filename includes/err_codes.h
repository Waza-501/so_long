/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   err_codes.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/04 15:18:28 by owen          #+#    #+#                 */
/*   Updated: 2025/03/19 12:40:46 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_CODES_H
# define ERR_CODES_H
# define INPUT_ERR		"Input error. Please use ./so_long <FILE.ber>."
# define FILE_TYPE		"There was an error reading the map. Please make sure\
the map is a .ber file."
# define FD_ERROR		"File could not be opened. Make sure the file exists,\
and can be opened."
# define MEM_ERROR		"There was an issue allocating memory."
# define MAP_RECT		"Please make sure the map is a rectangle."

#endif