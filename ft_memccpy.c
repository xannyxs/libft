/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:57:43 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2020/11/20 14:57:44 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	s = (const unsigned char*)src;
	d = (unsigned char*)dest;
	i = 0;
	while (n != 0)
	{
		n--;
		*d = *s;
		d++;
		s++;
		i++;
		if (*s == (unsigned char)c)
		{
			*d = *s;
			d++;
			s++;
			return (dest + i + 1);
		}
	}
	return (NULL);
}
