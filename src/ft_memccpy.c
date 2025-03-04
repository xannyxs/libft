/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:57:43 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/11/24 17:03:04 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

void *ft_memccpy(void *dest, const void *src, int32_t c, size_t n) {
  uint8_t *ds = (uint8_t *)dest;
  const uint8_t *sr = (const uint8_t *)src;

  for (size_t i = 0; i < n; i++) {
    ds[i] = sr[i];
    if (sr[i] == (uint8_t)c) {
      return (void *)(ds + i + 1);
    }
  }
  return NULL;
}
