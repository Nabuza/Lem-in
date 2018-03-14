/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_samelink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:31:40 by nagaloul          #+#    #+#             */
/*   Updated: 2017/05/07 14:01:24 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static	int		ft_secondword(char *links, char *line)
{
	int	i;

	i = 1;
	line = ft_strchr(line, '-');
	links = ft_strchr(links, '-');
	if (!ft_strcmp(line, links))
		return (1);
	return (0);
}

static	int		ft_firstword2(char *links, char *line)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	line = ft_strchr(line, '-');
	while (line[i] != '\0' && links[j] != '\0' && links[j] != '-')
	{
		if (line[i] != links[j])
			return (0);
		i++;
		j++;
	}
	if (line[i] != '\0' || links[j] != '-')
		return (0);
	return (1);
}

static	int		ft_firstword(char *links, char *line)
{
	int	i;

	i = 0;
	while (links[i] != '\0' && links[i] != '-' && line[i] != '\0')
	{
		if (links[i] != line[i])
			return (0);
		i++;
	}
	if (line[i] != '-')
		return (0);
	return (1);
}

int				ft_samelink(char *links, char *line)
{
	if (ft_firstword(links, line) || ft_firstword2(links, line))
		if (ft_firstword2(line, links) || ft_secondword(links, line))
			return (0);
	return (1);
}
