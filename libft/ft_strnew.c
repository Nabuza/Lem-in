/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:32:48 by nagaloul          #+#    #+#             */
/*   Updated: 2017/05/09 19:20:34 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*a;
	size_t		i;

	i = 0;
	if (!(a = ((char*)malloc(sizeof(char) * size + 1))))
		return (NULL);
	while (i <= size)
	{
		a[i] = '\0';
		i++;
	}
	return (a);
}
