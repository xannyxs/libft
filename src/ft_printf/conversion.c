/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversion.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 16:21:50 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/19 15:40:36 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.h"
#include "ft_printf.h"

#include <unistd.h>

uint32_t conversion(t_width *flags, char *str, va_list ap) {
  int32_t len = 0;
  const t_conversions s_conversions[] = {
      {'s', &print_s}, {'c', &print_c}, {'i', &print_id},   {'d', &print_id},
      {'u', &print_u}, {'p', &print_p}, {'%', &print_perc},
  };

  for (int32_t i = 0; s_conversions[i].key; i++) {
    if (*str == s_conversions[i].key) {
      len = s_conversions[i].func(flags, ap);

      return len;
    }
  }
  if (*str == 'x') {
    len = print_x(flags, ap, false);
  }

  if (*str == 'X') {
    len = print_x(flags, ap, true);
  }

  return len;
}
