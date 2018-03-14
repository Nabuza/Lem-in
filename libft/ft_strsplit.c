/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:01:06 by nagaloul          #+#    #+#             */
/*   Updated: 2017/04/30 15:06:10 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;

	if (s == NULL)
		return (NULL);
	i = ft_decoupe(s, c);
	if (!(str = (char**)malloc(sizeof(char*) * (ft_decoupe(s, c) + 1))))
		return (NULL);
	ft_taille(str, s, c, i);
	ft_remp(str, s, c, i);
	return (str);
}
