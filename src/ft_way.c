/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_way.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:21:17 by nagaloul          #+#    #+#             */
/*   Updated: 2017/05/11 16:55:27 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

static	void	ft_last_ants(t_list *end, int ant)
{
	t_list	*temp;

	temp = end;
	while (temp->ants != ant)
	{
		if (end->next->ants == ant)
		{
			end->ants = ant;
			ft_putchar('L');
			ft_putnbr(end->ants);
			ft_putchar('-');
			ft_putendl(end->data);
			end = temp;
		}
		else
		{
			end->ants = end->next->ants;
			ft_putchar('L');
			ft_putnbr(end->ants);
			ft_putchar('-');
			ft_putstr(end->data);
			ft_putstr(" ");
			end = end->next;
		}
	}
}

static	void	ft_onmyway(t_list *end, char *start, int i)
{
	while (end->next)
	{
		if (!ft_strcmp(end->next->data, start))
		{
			end->ants = i;
			ft_putchar('L');
			ft_putnbr(end->ants);
			ft_putchar('-');
			ft_putstr(end->data);
			ft_putchar('\n');
			break ;
		}
		else if (end->next->ants != 0)
		{
			end->ants = end->next->ants;
			ft_putchar('L');
			ft_putnbr(end->ants);
			ft_putchar('-');
			ft_putstr(end->data);
			ft_putstr(" ");
		}
		end = end->next;
	}
}

void			ft_way(int ant, t_list *end, char *start)
{
	t_list	*temp;
	int		i;

	temp = end;
	while (end->next)
	{
		end->ants = 0;
		end = end->next;
	}
	end->ants = ant;
	end = temp;
	i = 1;
	while (temp->ants < ant)
	{
		ft_onmyway(end, start, i);
		i++;
		end = temp;
		if (i > ant)
		{
			ft_last_ants(end, ant);
			break ;
		}
	}
}
