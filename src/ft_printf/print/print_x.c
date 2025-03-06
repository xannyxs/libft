/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_x.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/07 16:02:52 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/19 15:43:08 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>

uint32_t print_x(t_width *flags, va_list ap, bool is_uppercase) {
  int32_t len = 0;
  uint32_t hex = va_arg(ap, int);

  if (flags->width > 0) {
    int32_t amount_of_spaces = flags->width - ft_numlen(hex, len);
    while (len < amount_of_spaces) {
      write(STDOUT_FILENO, " ", 1);
      len++;
    }

    len += convert_hex(hex, is_uppercase);
    return len;
  }
}
