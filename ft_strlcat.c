/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:51:01 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2020/11/20 14:51:07 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (dst[i] != '\0' && i < n)
		i++;
	while (*src && (i + 1) < n)
	{
		dst[i] = *src;
		src++;
		i++;
	}
	if (i < n)
		dst[i] = '\0';
	return (i + ft_strlen((char *)src));
}
