/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:47:21 by nagaloul          #+#    #+#             */
/*   Updated: 2017/04/30 15:06:10 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int					i;
	unsigned	char	k;

	i = ft_strlen(s);
	k = (unsigned char)c;
	while (i >= 0 && s[i] != k)
		i--;
	if (i == -1)
		return (NULL);
	return ((char *)s + i);
}
