/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_array.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/03 16:12:23 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/06/07 17:41:45 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

void ft_print_array(char *array[]) {
  int32_t x = 0;

  for (int32_t y = 0; array[y]; y++) {
    while (array[y][x] != '\0') {
      if (write(STDOUT_FILENO, &array[y][x], 1) < 0) {
        perror("ft_print_array: write error");
      }

      x++;
    }
    if (write(STDOUT_FILENO, "\n", 1) < 0) {
      perror("ft_print_array: write error");
    }
    x = 0;
  }
}
