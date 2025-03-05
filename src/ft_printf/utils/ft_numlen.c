/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: xander <xander@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 13:26:46 by xander        #+#    #+#                 */
/*   Updated: 2022/04/19 13:26:58 by xander        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_numlen(int n, unsigned int len)
{
	long	i;

	i = n;
	if (i < 0)
	{
		i = i * -1;
		len++;
	}
	if (i > 9)
	{
		len = ft_numlen(i / 10, len);
		len = ft_numlen(i % 10, len);
	}
	else
	{
		i = i + '0';
		len++;
	}
	return (len);
}
