/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 09:36:35 by nagaloul          #+#    #+#             */
/*   Updated: 2017/04/30 15:06:10 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		*ft_strtrim(char const *s)
{
	int		i;
	int		k;
	int		g;
	char	*str;

	if (s == NULL)
		return (NULL);
	g = 0;
	k = ft_strlen(s);
	i = 0;
	k--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while ((s[k] == ' ' || s[k] == '\t' || s[k] == '\n') && k > i)
		k--;
	if (!(str = (char*)malloc(sizeof(char) * (k - i + 2))))
		return (NULL);
	while (i <= k)
	{
		str[g] = s[i];
		g++;
		i++;
	}
	str[g] = '\0';
	return (str);
}
