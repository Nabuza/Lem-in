/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 10:21:03 by nagaloul          #+#    #+#             */
/*   Updated: 2017/04/30 15:06:08 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_remp(char **tab, char const *s, char c, int g)
{
	int		i;
	int		l;
	int		v;

	i = 0;
	l = 0;
	v = 0;
	while (s[i] != '\0' && l < g)
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			tab[l][v] = s[i];
			i++;
			v++;
		}
		tab[l][v] = '\0';
		l++;
		v = 0;
	}
	tab[l] = 0;
	return (tab);
}
