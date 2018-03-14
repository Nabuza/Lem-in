/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:35:53 by nagaloul          #+#    #+#             */
/*   Updated: 2017/04/30 15:06:06 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_neg(int n)
{
	int				a;
	long			b;
	long			c;
	char			*str;

	a = 2;
	c = (long)n * -1;
	b = c;
	while (b >= 10)
	{
		b = b / 10;
		a++;
	}
	if (!(str = (char*)malloc(sizeof(char) * a + 1)))
		return (NULL);
	str[a] = '\0';
	a--;
	while (a >= 1)
	{
		str[a] = c % 10 + 48;
		c = c / 10;
		a--;
	}
	str[a] = '-';
	return (str);
}

char		*ft_itoa(int n)
{
	int		a;
	int		b;
	char	*str;

	a = 1;
	if (n < 0)
		return (ft_neg(n));
	b = n;
	while (b >= 10)
	{
		b = b / 10;
		a++;
	}
	if (!(str = (char*)malloc(sizeof(char) * a + 1)))
		return (NULL);
	str[a] = '\0';
	a--;
	while (a >= 0)
	{
		str[a] = n % 10 + 48;
		n = n / 10;
		a--;
	}
	return (str);
}
