/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:50:44 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2020/11/20 14:50:50 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

void ft_putchar_fd(char c, int32_t fd) {
  if (write(fd, &c, 1) < 0) {
    perror("ft_putchar_fd: write error");
  };
}
