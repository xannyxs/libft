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
	size_t	i;
	int		j;
	char	*str2;

	str2 = (char *)str;
	if (!to_find[0])
		return (str2);
	i = 0;
	j = 0;
	while (*str2 && len)
	{
		while (str2[i] == to_find[j] && str[i] && len)
		{
			len--;
			i++;
			j++;
			if (!to_find[j])
				return (str2);
		}
		j = 0;
		i = 0;
		str2++;
		len--;
	}
	return (NULL);
}
