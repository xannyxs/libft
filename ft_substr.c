/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:51:17 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2020/11/20 14:51:18 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;
	size_t			slen;

	i = 0;
	if (str == NULL)
		return (NULL);
	slen = ft_strlen(str);
	substr = malloc(sizeof(char) * len + 1);
	if (substr == NULL)
		return (NULL);
	if (slen < start)
	{
		substr[0] = '\0';
		return (substr);
	}
	while (str[start] != '\0' && len > i)
	{
		substr[i] = str[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
