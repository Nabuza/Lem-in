/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:19:34 by nagaloul          #+#    #+#             */
/*   Updated: 2017/04/30 15:06:06 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*str;
	char	*dest;
	size_t	i;

	i = 0;
	str = (char*)src;
	dest = (char*)dst;
	while (i < n)
	{
		dest[i] = str[i];
		i++;
	}
	return (dest);
}
