/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recover.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 18:10:18 by nagaloul          #+#    #+#             */
/*   Updated: 2017/05/11 16:30:44 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static	int		ft_last_check(t_list *rooms, char **start, t_list **end)
{
	int	i;

	i = 0;
	*start = NULL;
	while (rooms)
	{
		if (!ft_strcmp(rooms->data, "##end"))
		{
			rooms->next->data[ft_strnlen(rooms->next->data, ' ')] = '\0';
			ft_push_back(end, rooms->next->data);
			i++;
		}
		if (!ft_strcmp(rooms->data, "##start"))
		{
			rooms->next->data[ft_strnlen(rooms->next->data, ' ')] = '\0';
			*start = ft_strdup(rooms->next->data);
			i++;
		}
		rooms = rooms->next;
	}
	if (i != 2)
		return (0);
	return (1);
}

static	int		ft_match(char *link, char *room, t_list **end)
{
	char	*temp;

	temp = link;
	if (!ft_strchr(link, '-'))
		return (0);
	link[ft_strnlen(link, '-')] = '\0';
	if (!ft_strcmp(link, room))
	{
		link[ft_strlen(link)] = '-';
		link = ft_strchr(link, '-');
		ft_push_back(end, link + 1);
		ft_memset(temp, '\0', ft_strlen(temp));
		return (1);
	}
	link[ft_strlen(link)] = '-';
	link = ft_strchr(link, '-');
	if (!ft_strcmp(link + 1, room))
	{
		*link = '\0';
		ft_push_back(end, temp);
		*link = '-';
		ft_memset(temp, '\0', ft_strlen(temp));
		return (1);
	}
	return (0);
}

static	void	ft_pop(t_list **end)
{
	t_list	*temp;
	t_list	*elem;

	temp = *end;
	elem = temp;
	if (temp->next == NULL)
	{
		ft_strdel(&temp->data);
		free(temp);
		temp = NULL;
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		while (elem->next->next)
			elem = elem->next;
		ft_strdel(&temp->data);
		free(temp);
		elem->next = NULL;
	}
}

static	int		ft_solve(char *start, t_list **end, t_list *temp)
{
	t_list	*links;

	links = temp;
	if (!ft_strcmp(start, (*end)->data))
		return (1);
	while (links)
	{
		if (ft_match(links->data, (*end)->data, end))
		{
			if (ft_solve(start, &(*end)->next, temp))
				return (1);
			ft_pop(end);
		}
		links = links->next;
	}
	return (0);
}

int				ft_recover(int ant, t_list *rooms, t_list *links)
{
	char	*start;
	t_list	*end;

	end = NULL;
	if (!ft_last_check(rooms, &start, &end))
	{
		ft_putendl("ERROR");
		return (0);
	}
	if (!(ft_solve(start, &end, links)))
	{
		ft_putendl("no way found !");
		ft_pop(&end);
		ft_strdel(&start);
		return (1);
	}
	ft_way(ant, end, start);
	ft_freestrings(end);
	ft_list_clear(&end);
	ft_strdel(&start);
	return (1);
}
