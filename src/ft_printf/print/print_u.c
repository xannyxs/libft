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
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

int32_t ft_putnbr(int32_t n, int32_t len) {
  int64_t i = n;

  if (i < 0) {
    write(STDOUT_FILENO, "-", 1);
    i = i * -1;
    len++;
  }

  if (i > 9) {
    len = ft_putnbr(i / 10, len);
    len = ft_putnbr(i % 10, len);
  } else {
    i = i + '0';
    write(STDOUT_FILENO, &i, 1);
    len++;
  }

  return len;
}

uint32_t ft_put_unsigned_nbr_fd(unsigned int n, int fd, int len) {
  if (n > 9) {
    len = ft_putnbr(n / 10, len);
    len = ft_putnbr(n % 10, len);
  } else {
    n = n + '0';
    write(fd, &n, 1);
    len++;
  }
  return (len);
}

uint32_t print_int_width(t_width *flags, unsigned int number) {
  int len;
  int amount_of_spaces;

  len = 0;
  amount_of_spaces = flags->width - ft_numlen(number, len);
  while (len < amount_of_spaces) {
    write(STDOUT_FILENO, " ", 1);
    len++;
  }
  return (len);
}

uint32_t print_u(t_width *flags, va_list ap) {
  unsigned int len;
  unsigned int number;

  len = 0;
  number = (unsigned int)va_arg(ap, int);
  if (flags->width > 0)
    len += print_int_width(flags, number);
  len += ft_put_unsigned_nbr_fd(number, STDOUT_FILENO, len) - len;
  return (len);
}
