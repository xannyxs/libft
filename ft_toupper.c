/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:51:42 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2020/11/20 14:51:43 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int argc)
{
	if (argc >= 'a' && argc <= 'z')
		argc -= 32;
	return (argc);
}
