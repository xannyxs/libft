/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 15:07:58 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2021/11/24 16:55:10 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((str1[i] != 0 && str2[i] != 0) && (str1[i] == str2[i] && n - 1 > i))
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
