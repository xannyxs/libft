/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 15:07:11 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2020/11/20 15:07:12 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *str, int c)
{
	char *str2;

	str2 = (char *)str;
	while (*str2 != c)
	{
		if (*str2 == '\0')
		{
			return (NULL);
		}
		str2++;
	}
	return (str2);
}
