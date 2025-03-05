/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_hex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 15:43:03 by xander        #+#    #+#                 */
/*   Updated: 2022/04/19 15:43:39 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

int32_t convert_hex(uint64_t number, bool is_uppercase) {
  size_t len = 0;
  const char *caps_digits = "0123456789ABCDEF";
  const char *nocaps_digits = "0123456789abcdef";

  if (number > 15) {
    len += convert_hex(number / 16, is_uppercase);
  }

  number %= 16;
  if (is_uppercase == true) {
    if (write(STDOUT_FILENO, &caps_digits[number], 1) < 0) {
      perror("Error in write");
    }
  }

  if (is_uppercase == false) {
    if (write(STDOUT_FILENO, &nocaps_digits[number], 1) < 0) {
      perror("Error in write");
    }
  }

  len += 1;
  return len;
}
