/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:47:57 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2020/11/20 14:47:59 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*s2;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	while (s1[len] == *set || s1[len] == '\0' || s1[len] <= ' ')
		len--;
	while (s1[i] == *set || s1[i] <= ' ')
	{
		i++;
		len--;
	}
	if (len <= 0)
	{
		len = -1;
		s2 = malloc(sizeof(char));
	}
	else
		s2 = malloc(sizeof(char) * len + 2);
	if (!s2)
		return (NULL);
	while (len-- >= 0)
		s2[j++] = s1[i++];
	s2[j] = '\0';
	return (s2);
}
