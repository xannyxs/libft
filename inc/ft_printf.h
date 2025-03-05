/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <xvoorvaa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/24 19:26:37 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2022/04/19 15:43:50 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define FLAGS "-0 "
#define CONV "cspdiuxX%"

typedef struct s_width {
  uint32_t width;
} t_width;

/*
        PRINT
*/

unsigned int print_p(t_width *flags, va_list ap);

unsigned int print_x(t_width *flags, va_list ap, bool is_uppercase);

unsigned int print_u(t_width *flags, va_list ap);

unsigned int print_c(t_width *flags, va_list ap);

unsigned int print_id(t_width *flags, va_list ap);

unsigned int print_s(t_width *flags, va_list ap);

unsigned int print_perc(t_width *flags, va_list ap);

/*
        SRC
*/

int ft_printf(const char *str, ...);

uint32_t conversion(t_width *flags, char *str, va_list ap);

int convert_hex(uint64_t number, bool is_uppercase);

int ft_numlen(int n, unsigned int len);

#endif
