/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 10:41:50 by nagaloul          #+#    #+#             */
/*   Updated: 2017/04/30 15:06:09 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t d_len;
	size_t s_len;
	size_t res_len;

	d_len = ft_strlen((const char*)dst);
	s_len = ft_strlen(src);
	res_len = 0;
	if (d_len >= size)
		return (size + s_len);
	while (src[res_len] && (d_len + res_len < size - 1))
	{
		dst[d_len + res_len] = (char)src[res_len];
		res_len++;
	}
	dst[d_len + res_len] = '\0';
	return (d_len + s_len);
}
