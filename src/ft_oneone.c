/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oneone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:36:42 by nagaloul          #+#    #+#             */
/*   Updated: 2017/05/11 16:40:02 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		ft_oneone(char *line)
{
	if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
		return (1);
	if (ft_countchar(line, '#') == 0)
		return (1);
	return (0);
}
