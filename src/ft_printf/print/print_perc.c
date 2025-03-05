/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_perc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/25 10:55:53 by xander        #+#    #+#                 */
/*   Updated: 2022/04/19 15:15:08 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <unistd.h>
#include <stdarg.h>

static unsigned int	print_width(t_flags *flags)
{
	int	len;
	int	amount_of_spaces;

	len = 0;
	amount_of_spaces = flags->width - 1;
	while (len <= amount_of_spaces)
	{
		write(STDOUT_FILENO, " ", 1);
		len++;
	}
	return (len);
}

unsigned int	print_perc(t_flags *flags, va_list ap)
{
	unsigned int	len;

	len = 0;
	(void) ap;
	if (flags->width > 0)
		print_width(flags);
	write(STDOUT_FILENO, "%", 1);
	return (len + 1);
}
