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

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t len;
	size_t i;
	size_t j;

	len = 0;
	i = 0;
	j = 0;
	while (dest[len] != '\0' && n > len)
		len++;
	while (src[i++] != '\0')
		len++;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && n > i + 1)
		dest[i++] = src[j++];
	if (i != n)
		dest[i] = '\0';
	return (len);
}
