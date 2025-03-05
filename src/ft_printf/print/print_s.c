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
#include "libft.h"

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

uint32_t print_string_width(t_flags *flags, char *str) {
  int len = 0;
  int amount_of_spaces;

  if (!str) {
    amount_of_spaces = flags->width - 6;
  } else {
    amount_of_spaces = flags->width - (int)ft_strlen(str);
  }

  while (len < amount_of_spaces) {
    write(STDOUT_FILENO, " ", 1);
    len++;
  }

  return len;
}

uint32_t print_s(t_flags *flags, va_list ap) {
  uint32_t len = 0;
  char *str = va_arg(ap, char *);
  ;

  if (flags->width > 0) {
    len += print_string_width(flags, str);
  }

  if (!str) {
    write(STDOUT_FILENO, "(null)", 6);
    return len + 6;
  }

  for (int32_t i = 0; str[i]; i++) {
    if (write(STDOUT_FILENO, &str[i], 1) < 0) {
      perror("Error in write");
    };
    len++;
  }

  return len;
}
