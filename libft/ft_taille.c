/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_taille.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 10:00:02 by nagaloul          #+#    #+#             */
/*   Updated: 2017/04/30 15:06:11 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_taille(char **tab, char const *s, char c, int g)
{
	int		i;
	int		k;
	int		l;

	l = 0;
	k = 0;
	i = 0;
	while (s[i] != '\0' && l < g)
	{
		while (s[i] == c)
			i++;
		while (s[i + k] != c && s[i + k] != '\0')
			k++;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (!(tab[l] = (char*)malloc(sizeof(char) * (k + 1))))
			return (NULL);
		l++;
		k = 0;
	}
	return (tab);
}
