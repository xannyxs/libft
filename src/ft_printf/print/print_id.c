/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_id.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/03 17:12:39 by xander        #+#    #+#                 */
/*   Updated: 2022/04/19 14:40:16 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>
#include <unistd.h>

static unsigned int	print_int_width(t_flags *flags, int number)
{
	int	len;
	int	amount_of_spaces;

	len = 0;
	amount_of_spaces = flags->width - ft_numlen(number, len);
	while (len < amount_of_spaces)
	{
		write(STDOUT_FILENO, " ", 1);
		len++;
	}
	return (len);
}

unsigned int	print_id(t_flags *flags, va_list ap)
{
	int				number;
	unsigned int	len;

	len = 0;
	number = va_arg(ap, int);
	if (flags->width > 0)
		len += print_int_width(flags, number);
	len += ft_putnbr_fd(number, STDOUT_FILENO, len) - len;
	return (len);
}
