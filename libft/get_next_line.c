/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:54:26 by nagaloul          #+#    #+#             */
/*   Updated: 2017/04/30 15:06:11 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		isn(char *s, char c)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str;
	char		*temp;
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (!str)
		str = ft_strnew(1);
	while (!(ft_strchr(str, '\n')))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == 0)
			break ;
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		temp = ft_strjoin(str, buf);
		ft_strdel(&str);
		str = temp;
	}
	if (ft_strlen(str) == 0)
		return (0);
	*line = ft_strsub(str, 0, isn(str, '\n'));
	temp = ft_strsub(str, isn(str, '\n') + 1, ft_strlen(&str[isn(str, '\n')]));
	ft_strdel(&str);
	str = temp;
	return (1);
}
