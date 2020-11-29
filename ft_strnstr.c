/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 15:08:15 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2020/11/20 15:08:16 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t pos;
	size_t i;

	if (!*to_find)
		return ((char*)str);
	pos = 0;
	while (str[pos] && pos < len)
	{
		if (str[pos] == to_find[0])
		{
			i = 1;
			while (to_find[i] && str[pos + i] == to_find[i] &&
					(pos + i) < len)
				i++;
			if (to_find[i])
				return ((char*)&str[pos]);
		}
		pos++;
	}
	return (0);
}
