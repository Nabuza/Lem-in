/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 21:32:03 by nagaloul          #+#    #+#             */
/*   Updated: 2017/05/11 16:43:04 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static	int		ft_sameroom(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	i = ft_strnlen(line, '-');
	line[i] = '\0';
	i++;
	if (!ft_strcmp(line, line + i))
	{
		line[ft_strlen(line)] = '-';
		return (0);
	}
	line[ft_strlen(line)] = '-';
	return (1);
}

static	int		ft_notagain(t_list **links, char *line)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *links;
	if (ft_strchr(line, '#'))
		return (0);
	if (!ft_sameroom(line))
		return (0);
	if (!temp)
		return (1);
	while (temp)
	{
		if (!ft_samelink(temp->data, line))
			return (0);
		temp = temp->next;
	}
	return (1);
}

static	int		ft_check_links(char *st, t_list *lst)
{
	int	i;

	i = 0;
	if (ft_countchar(st, '-') != 1 && !ft_strchr(st, '#'))
		return (0);
	while (lst)
	{
		while (lst && ft_strchr(lst->data, '#'))
			lst = lst->next;
		if (!lst)
			break ;
		lst->data[ft_strnlen(lst->data, ' ')] = '\0';
		st[ft_strnlen(st, '-')] = '\0';
		if (!ft_strcmp(st, lst->data))
			i++;
		st[ft_strlen(st)] = '-';
		if (!ft_strcmp(ft_strchr(st, '-') + 1, lst->data))
			i++;
		lst->data[ft_strlen(lst->data)] = ' ';
		lst = lst->next;
	}
	if (i > 1)
		return (1);
	return (0);
}

static	void	ft_fill_links(t_list **links, char *line, t_list *rooms)
{
	if (ft_check_links(line, rooms) && ft_sameroom(line))
		ft_push_back(links, line);
	ft_strdel(&line);
	while (get_next_line(0, &line))
	{
		if (ft_countchar(line, '#') > 2)
		{
			ft_strdel(&line);
			break ;
		}
		if (ft_countchar(line, '#') == 0)
		{
			if (!ft_check_links(line, rooms))
			{
				ft_strdel(&line);
				break ;
			}
		}
		if (ft_notagain(links, line))
			ft_push_back(links, line);
		ft_strdel(&line);
	}
}

int				ft_pars(char *ants)
{
	t_list	*links;
	t_list	*rooms;
	char	*line;

	rooms = NULL;
	line = NULL;
	links = NULL;
	while (get_next_line(0, &line))
	{
		if (ft_strchr(line, '-'))
		{
			ft_fill_links(&links, line, rooms);
			break ;
		}
		if (ft_oneone(line))
			ft_push_back(&rooms, line);
		ft_strdel(&line);
	}
	if (!(ft_check(ants, rooms, links)))
		write(1, "ERROR\n", 6);
	ft_freestrings(rooms);
	ft_list_clear(&rooms);
	ft_freestrings(links);
	ft_list_clear(&links);
	return (0);
}
