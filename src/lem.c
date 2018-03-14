/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 21:28:50 by nagaloul          #+#    #+#             */
/*   Updated: 2017/05/11 17:03:13 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int	main(int ac, char **av)
{
	char	*ants;
	char	*line;

	(void)av;
	if (ac > 1)
		return (0);
	while (get_next_line(0, &line))
	{
		if (ft_countchar(line, '#') == 1)
			ft_strdel(&line);
		else
			break ;
	}
	ants = ft_strdup(line);
	ft_strdel(&line);
	ft_pars(ants);
	return (0);
}
