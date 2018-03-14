/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:28:49 by nagaloul          #+#    #+#             */
/*   Updated: 2017/04/30 15:06:10 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t k;
	size_t z;

	i = 0;
	k = 0;
	z = 0;
	while (big[i] != '\0' && i < len)
	{
		while (big[i + k] == little[k] && z < len)
		{
			k++;
			if (little[k] == '\0')
				return ((char *)big + i);
			z = i + k;
		}
		i++;
		k = 0;
	}
	if (little[0] == '\0')
		return ((char*)big);
	return (NULL);
}
