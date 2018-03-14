/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 10:32:02 by nagaloul          #+#    #+#             */
/*   Updated: 2017/04/30 15:06:07 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str;
	char	*dest;
	size_t	i;

	i = 0;
	str = (char*)src;
	dest = (char*)dst;
	if (str < dest && len > 0)
	{
		i = i + len;
		i--;
		while (i > 0)
		{
			dest[i] = str[i];
			i--;
		}
		dest[i] = str[i];
		return (dest);
	}
	dest = ft_memcpy(dest, str, len);
	return (dest);
}
