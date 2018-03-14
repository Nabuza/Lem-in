/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:57:59 by nagaloul          #+#    #+#             */
/*   Updated: 2017/04/30 15:06:10 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (big[i] != '\0')
	{
		while (big[i + k] == little[k])
		{
			k++;
			if (little[k] == '\0')
				return ((char *)big + i);
		}
		i++;
		k = 0;
	}
	if (little[0] == '\0')
		return ((char *)big);
	return (NULL);
}
