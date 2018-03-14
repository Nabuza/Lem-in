/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 15:53:32 by nagaloul          #+#    #+#             */
/*   Updated: 2017/05/11 16:43:19 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H
# include "../libft/libft.h"
# include "stdlib.h"
# include "unistd.h"

typedef	struct		s_list
{
	struct s_list	*next;
	char			*data;
	int				ants;
}					t_list;

int					ft_check(char *ant, t_list *rooms, t_list *links);
int					main(int ac, char **av);
int					ft_pars(char *ants);
void				ft_push_back(t_list **begin_list, char *data);
t_list				*ft_create_elem(char *data);
int					ft_recover(int ant, t_list *rooms, t_list *link);
void				ft_list_clear(t_list **begin_list);
int					ft_samelink(char *links, char *line);
void				ft_way(int ant, t_list *end, char *start);
void				ft_freestrings(t_list *elem);
int					ft_oneone(char *line);

#endif
