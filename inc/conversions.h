/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversions.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 15:08:14 by xander        #+#    #+#                 */
/*   Updated: 2022/04/19 15:10:22 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include "ft_printf.h"
#include <stdint.h>

typedef struct s_conversions {
  char key;
  uint32_t (*func)(t_width *, va_list);
} t_conversions;

#endif
