/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_s.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/07 15:57:00 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/19 14:18:18 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>
#include <unistd.h>

static unsigned int	print_string_width(t_flags *flags, char *str)
{
	int	len;
	int	amount_of_spaces;

	len = 0;
	if (!str)
		amount_of_spaces = flags->width - 6;
	else
		amount_of_spaces = flags->width - (int)ft_strlen(str);
	while (len < amount_of_spaces)
	{
		write(STDOUT_FILENO, " ", 1);
		len++;
	}
	return (len);
}

unsigned int	print_s(t_flags *flags, va_list ap)
{
	int				i;
	char			*str;
	unsigned int	len;

	i = 0;
	len = 0;
	str = va_arg(ap, char *);
	if (flags->width > 0)
		len += print_string_width(flags, str);
	if (!str)
	{
		write(STDOUT_FILENO, "(null)", 6);
		return (6 + len);
	}
	while (str[i] != '\0')
	{
		write(STDOUT_FILENO, &str[i], 1);
		len++;
		i++;
	}
	return (len);
}
