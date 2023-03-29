/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_messages.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 15:04:11 by ohearn        #+#    #+#                 */
/*   Updated: 2023/03/29 15:42:10 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H

# define ERR_INPUT		"Input error. Please format it as ./so_long <MAP FILE>"
# define ERR_FT			"File type incorrect. Please use maps ending in .ber"
# define ERR_FD			"Couldn't open file. Please try again."
# define ERR_MEM		"Memory relates issue. Please try again."
# define ERR_MP_RECT    "Map size incorrect. Please use a rectangular map."
# define ERR_MP_WALLS	"Map isn't surrounded by walls."
# define ERR_MP_CHAR	"Invalid character found. Please remove it"
# define ERR_MP_NOSPWN	"No player spawn found. Please add 'P' to the map"
# define ERR_MP_SPWN	"Too many spawns found. Please leave one 'P' on the map"
# define ERR_MP_NOEXIT	"No player exit found. Please add 'E' to the map"
# define ERR_MP_EXIT	"Too many exits found. Please leave one 'E' on the map"
# define ERR_MP_NOCOL	"No collectibles found. Please add 'C' to the map"
# define ERR_MP_UNSOLV	"Map unsolvable. Please try again with a different map"

#endif