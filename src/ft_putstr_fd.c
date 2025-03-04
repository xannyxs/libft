/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:58:53 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2020/11/20 14:58:54 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

void ft_putstr_fd(char *str, int32_t fd) {
  if (!str) {
    return;
  }

  for (int32_t i = 0; str[i]; i++) {
    if (write(fd, &str[i], 1) < 0) {
      perror("ft_putstr_fd: write error");
    }
  }
}
