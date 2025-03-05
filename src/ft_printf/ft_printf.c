/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 15:11:49 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/19 13:15:02 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

uint32_t len_of_width(const char *str, int32_t *offset) {
  uint32_t width = 0;
  int32_t i = 0;

  while (ft_isdigit(str[i])) {
    width = width * 10 + (str[i] - '0');
    i++;
  }

  *offset = i;
  return width;
}

int32_t ft_printf(const char *str, ...) {
  va_list arg;
  uint32_t len = 0;
  t_flags flags = {0};

  va_start(arg, str);

  for (int32_t i = 0; str[i]; i++) {
    if (str[i] == '%') {
      flags.width = 0;
      i += 1;

      if (ft_isdigit(str[i]) == true) {
        int32_t offset = 0;
        flags.width = len_of_width(&str[i], &offset);
        i += offset;
      }

      if (ft_strchr(CONV, str[i])) {
        len += conversion(&flags, (char *)&str[i], arg);
      }

      continue;
    }

    if (write(STDOUT_FILENO, &str[i], 1) < 0) {
      perror("error in write");
    }
    len++;
  }

  va_end(arg);

  return len;
}
