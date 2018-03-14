/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:53:56 by nagaloul          #+#    #+#             */
/*   Updated: 2017/04/30 15:06:08 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned	char	o;
	int					i;

	i = 0;
	o = (unsigned char)c;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && s[i] != o)
		i++;
	if (o == '\0')
		return ((char*)s + i);
	if (s[i] == '\0')
		return (NULL);
	return ((char*)s + i);
}
