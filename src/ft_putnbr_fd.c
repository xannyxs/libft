/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:58:40 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/11/24 17:01:29 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdint.h>
#include <stdio.h>

void ft_putnbr_fd(int32_t n, int32_t fd) {
  int64_t i = n;

  if (i < 0) {
    if (write(fd, "-", 1) < 0) {
      perror("ft_putnbr_fd: write error");
    }
    i *= -1;
  }

  if (i > 9) {
    ft_putnbr_fd(i / 10, fd);
    ft_putnbr_fd(i % 10, fd);
    return;
  }

  i = i + '0';
  if (write(fd, &i, 1) < 0) {
    perror("ft_putnbr_fd: write error");
  }
}
