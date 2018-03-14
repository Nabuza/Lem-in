/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:07:23 by nagaloul          #+#    #+#             */
/*   Updated: 2017/04/30 15:06:06 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned	char	*a;
	unsigned	char	b;
	size_t				i;

	i = 0;
	b = (unsigned char)c;
	a = (unsigned char*)s;
	if (n <= 0)
		return (NULL);
	while (a[i] != b && i < n - 1)
		i++;
	if (i == n)
		return (NULL);
	if (a[i] != b)
		return (NULL);
	return (a + i);
}
