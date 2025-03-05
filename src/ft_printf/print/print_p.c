/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_p.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/07 16:04:30 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/19 14:51:35 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

static unsigned int print_int_width(t_width *flags, unsigned long long number) {
  int len = 0;
  int amount_of_spaces = flags->width - ft_numlen(number, len) - 3;

  while (len <= amount_of_spaces) {
    write(STDOUT_FILENO, " ", 1);
    len++;
  }

  return len;
}

uint32_t print_p(t_width *flags, va_list ap) {
  size_t len = 0;
  unsigned long long hex = (unsigned long long)va_arg(ap, void *);

  if (flags->width > 0) {
    len += print_int_width(flags, hex);
  }

  if (write(STDOUT_FILENO, "0x", 2) < 0) {
    perror("error in write");
  }

  len += convert_hex(hex, false);
  return len + 2;
}
