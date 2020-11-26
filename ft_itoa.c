/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:55:34 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2020/11/20 14:55:35 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countnbr(int count)
{
	int i;

	i = 0;
	while (count >= 10)
	{
		count = count / 10;
		i++;
	}
	if (count < 10)
	{
		count = count % 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		negative;
	char	*str;
	int		len;

	negative = 0;
	if (n == -2147483648)
		return(ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = n * -1;
		negative = 1;
	}
	len = ft_countnbr(n) + negative;
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len != 0)
	{
		len--;
		str[len] = n % 10 + '0';
		if (n >= 10)
			n = n / 10;
	}
	if (negative == 1)
		str[0] = '-';
	return (str);
}
