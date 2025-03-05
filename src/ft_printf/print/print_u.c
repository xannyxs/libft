/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_u.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/07 11:27:44 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/19 15:16:48 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>
#include <unistd.h>

#include <stdio.h>

static unsigned int	ft_put_unsigned_nbr_fd(unsigned int n, int fd, int len)
{
	if (n > 9)
	{
		len = ft_putnbr_fd(n / 10, fd, len);
		len = ft_putnbr_fd(n % 10, fd, len);
	}
	else
	{
		n = n + '0';
		write(fd, &n, 1);
		len++;
	}
	return (len);
}

static unsigned int	print_int_width(t_flags *flags, unsigned int number)
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

unsigned int	print_u(t_flags *flags, va_list ap)
{
	unsigned int	len;
	unsigned int	number;

	len = 0;
	number = (unsigned int) va_arg(ap, int);
	if (flags->width > 0)
		len += print_int_width(flags, number);
	len += ft_put_unsigned_nbr_fd(number, STDOUT_FILENO, len) - len;
	return (len);
}
