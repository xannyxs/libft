/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:55:34 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/11/24 16:53:11 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

char *ft_itoa(int n) {
  if (n == INT_MIN) {
    char *ret = ft_strdup("-2147483648");
    return ret;
  }

  bool negative = false;
  if (n < 0) {
    n = n * -1;
    negative = true;
  }

  int32_t len = count_digits(n);

  len += negative;
  char *str = ft_calloc(sizeof(char), len + 1);
  if (!str)
    return NULL;

  while (len != 0) {
    len--;
    str[len] = n % 10 + '0';
    if (n >= 10)
      n = n / 10;
  }

  if (negative == true)
    str[0] = '-';

  return str;
}
