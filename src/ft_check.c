/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 16:34:09 by nagaloul          #+#    #+#             */
/*   Updated: 2017/05/11 17:07:10 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static	int		ft_check_number(char *str)
{
	int	i;

	i = ft_strnlen(str, ' ') + 1;
	if (i == 1)
		return (0);
	if (ft_countchar(str, ' ') == 2)
	{
		if (str[i] == ' ')
			return (0);
		while (ft_isdigit(str[i]))
			i++;
		if (str[i] != ' ' || str[i + 1] == '\0')
			return (0);
		i++;
		while (ft_isdigit(str[i]))
			i++;
		if (str[i] == '\0')
			return (1);
	}
	return (0);
}

static	int		ft_check_gdr(char *str)
{
	if (!ft_strchr(str, '#'))
		if (!ft_check_number(str))
			return (0);
	if (ft_countchar(str, '#') > 2)
		return (0);
	return (1);
}

static	int		ft_check_room(t_list *rooms, char *ant)
{
	while (rooms)
	{
		if (!ft_check_gdr(rooms->data))
		{
			ft_strdel(&ant);
			return (0);
		}
		if (!ft_strcmp(rooms->data, "##start") && !rooms->next)
		{
			ft_strdel(&ant);
			return (0);
		}
		if (!ft_strcmp(rooms->data, "##end") && !rooms->next)
		{
			ft_strdel(&ant);
			return (0);
		}
		rooms = rooms->next;
	}
	return (1);
}

int				ft_check(char *ant, t_list *rooms, t_list *links)
{
	int		i;

	i = 0;
	if (!ant)
		return (0);
	while (ant[i])
	{
		if (!ft_isdigit(ant[i]))
		{
			ft_strdel(&ant);
			return (0);
		}
		i++;
	}
	if (!ft_isint(ant) || ft_atoi(ant) == 0)
	{
		ft_putendl("No ants");
		ft_strdel(&ant);
		return (1);
	}
	if (!(ft_check_room(rooms, ant)))
		return (0);
	ft_recover(ft_atoi(ant), rooms, links);
	ft_strdel(&ant);
	return (1);
}
