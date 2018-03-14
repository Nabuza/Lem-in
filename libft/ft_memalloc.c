/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:26:18 by nagaloul          #+#    #+#             */
/*   Updated: 2017/04/30 15:06:06 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*a;
	size_t	i;

	i = 0;
	if (!(a = ((char*)malloc(sizeof(char) * size))))
		return (NULL);
	while (i < size)
	{
		a[i] = '\0';
		i++;
	}
	return (a);
}
