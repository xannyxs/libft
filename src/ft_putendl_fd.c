/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:52:41 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2020/11/20 14:52:42 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

void ft_putendl_fd(char *str, int32_t fd) {
  if (!str) {
    return;
  }

  for (int32_t i = 0; str[i]; i++) {
    if (write(fd, &str[i], 1) < 0) {
      perror("ft_putendl_fd: write error");
    }
  }

  if (write(fd, "\n", 1) < 0) {
    perror("ft_putendl_fd: write error");
  }
}
