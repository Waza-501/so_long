/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fc_print_hex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/16 15:00:02 by ohearn        #+#    #+#                 */
/*   Updated: 2023/01/25 11:31:12 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"

int	hex_converter(unsigned long dec, int modif)
{
	unsigned int	hex;
	int				size;

	size = 0;
	hex = (dec % 16);
	if (dec > 15)
		size += hex_converter(dec / 16, modif);
	if (hex < 10)
		hex += 48;
	else
		hex += (55 + modif);
	size += fc_putchar(hex);
	return (size);
}

int	fc_print_hex(unsigned long dec, int id)
{
	int	size;
	int	modif;

	size = 0;
	modif = 0;
	if (id == 'p')
	{
		fc_putstr("0x");
		size += 2;
	}
	if (id == 'p' || id == 'x')
		modif += 32;
	size += hex_converter(dec, modif);
	return (size);
}
