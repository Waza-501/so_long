/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ohearn <ohearn@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/25 20:43:40 by ohearn        #+#    #+#                 */
/*   Updated: 2023/01/25 11:35:39 by ohearn        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header/libft.h"
#include <stdarg.h>

int	specifier(const char *string, va_list arg)
{	
	int		size;
	int		id;

	size = 0;
	id = string[size];
	if (string[size] == 'c')
		size += fc_print_cha(va_arg(arg, int));
	else if (string[size] == 's')
		size += fc_print_str(va_arg(arg, char *));
	else if (string[size] == 'p')
		size += fc_print_hex(va_arg(arg, unsigned long), id);
	else if (string[size] == 'd' || string[size] == 'i')
		size += fc_putnbr(va_arg(arg, int));
	else if (string[size] == 'u')
		size += fc_print_dec(va_arg(arg, unsigned int));
	else if (string[size] == 'x' || string[size] == 'X')
		size += fc_print_hex(va_arg(arg, unsigned int), id);
	else if (string[size] == '%')
		size += fc_putchar('%');
	return (size);
}

int	ft_printf(const char *string, ...)
{
	int					size;
	va_list				arg;

	size = 0;
	va_start(arg, string);
	while (*string)
	{
		if (*string == '%')
		{
			string++;
			size += specifier(string, arg);
		}
		else
			size += fc_putchar(*string);
		string++;
	}
	va_end(arg);
	return (size);
}
