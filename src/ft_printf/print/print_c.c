/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_c.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/07 11:47:14 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/19 14:44:49 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>
#include <stdarg.h>

static unsigned int	print_char_width(t_flags *flags)
{
	int	len;
	int	amount_of_spaces;

	len = 0;
	amount_of_spaces = flags->width - 1;
	while (len < amount_of_spaces)
	{
		write(STDOUT_FILENO, " ", 1);
		len++;
	}
	return (len);
}

unsigned int	print_c(t_flags *flags, va_list ap)
{
	int				flag_c;
	unsigned int	len;

	len = 0;
	flag_c = va_arg(ap, int);
	if (flags->width > 0)
		len += print_char_width(flags);
	write(STDOUT_FILENO, &flag_c, 1);
	return (len + 1);
}
