/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:58:24 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/11/24 16:53:55 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
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
