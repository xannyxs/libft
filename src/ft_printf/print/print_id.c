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

uint32_t ft_putnbr_fd(int n, unsigned int len) {
  long i;

  i = n;
  if (i < 0) {
    write(STDOUT_FILENO, "-", 1);
    i = i * -1;
    len++;
  }
  if (i > 9) {
    len = ft_putnbr_fd(i / 10, len);
    len = ft_putnbr_fd(i % 10, len);
  } else {
    i = i + '0';
    write(STDOUT_FILENO, &i, 1);
    len++;
  }

  return len;
}

uint32_t print_int_width(t_width *flags, int number) {
  int len = 0;
  int amount_of_spaces;

  amount_of_spaces = flags->width - ft_numlen(number, len);
  while (len < amount_of_spaces) {
    write(STDOUT_FILENO, " ", 1);
    len++;
  }
  return (len);
}

uint32_t print_id(t_width *flags, va_list ap) {
  int number = va_arg(ap, int);
  uint32_t len = 0;

  if (flags->width > 0) {
    len += print_int_width(flags, number);
  }

  len += ft_putnbr_fd(number, len) - len;
  return (len);
}
