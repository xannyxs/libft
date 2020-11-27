/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: xvoorvaa <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 14:59:03 by xvoorvaa      #+#    #+#                 */
/*   Updated: 2020/11/20 14:59:04 by xvoorvaa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_freearray(char **s, int i)
{
	while (i > 0)
	{
		i--;
		free(s[i]);
	}
	free(s);
	return (NULL);
}

size_t	ft_countwords(const char *str, int c)
{
	int			state;
	unsigned	counter;

	state = 0;
	counter = 0;
	while (*str)
	{
		if (*str == c)
			state = 0;
		else if (state == 0)
		{
			state = 1;
			counter++;
		}
		++str;
	}
	return (counter);
}

char	**ft_leukesplit(char const *s, char c, int word)
{
	char	**str;
	int		i;
	int		j;
	size_t	len;

	len = 0;
	i = 0;
	str = (char **)ft_calloc(sizeof(char *), word + 1);
	while (i < word)
	{
		while (s[len] == c)
			len++;
		j = len;
		while (s[len] && s[len] != c)
			len++;
		str[i] = ft_substr(s, j, len - j);
		if (str[i] == NULL)
			return (ft_freearray(str, i));
		i++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		word;
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	if (!s)
		return (NULL);
	word = ft_countwords(s, c);
	str = (char **)ft_calloc(sizeof(char *), word + 1);
	if (!str)
		return (NULL);
	if (i < word)
		str = ft_leukesplit(s, c, word);
	return (str);
}
