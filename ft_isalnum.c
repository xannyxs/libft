/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:53:06 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2020/11/20 14:53:08 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int argc)
{
	if ((argc < 97 || argc > 122) && (argc < 65 || argc > 90)\
	&& (argc < 48 || argc > 57))
		return (0);
	return (1);
}
