/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:54:49 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2020/11/20 14:54:55 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int negative;
	int answer;

	i = 0;
	answer = 0;
	negative = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
		{
			negative = -1;
			i++;
			if (str[i] >= '0' && str[i] <= '9')
				answer = answer * 10 + (str[i] - '0');
			else
				return (0);
		}
		else if (str[i] >= '0' && str[i] <= '9')
			answer = answer * 10 + (str[i] - '0');
		else if (str[i] == '\e')
			return (0);
		i++;
	}
	return (answer * negative);
}
