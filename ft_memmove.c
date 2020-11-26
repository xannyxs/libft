/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:58:24 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2020/11/20 14:58:27 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char*)dest;
	s = (char*)src;
	if (dest != NULL || src != NULL)
	{
		if (d > s)
			while (len)
			{
				len--;
				d[len] = s[len];
			}
		else
			while (len)
			{
				len--;
				*d = *s;
				d++;
				s++;
			}
	}
	return (dest);
}
