/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:39:07 by zlucan            #+#    #+#             */
/*   Updated: 2019/09/14 21:01:17 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*sc;
	unsigned char	cc;

	i = 0;
	cc = (unsigned char)c;
	sc = (unsigned char *)s;
	while (n--)
	{
		if (sc[i] == cc)
			return (sc + i);
		i++;
	}
	return (NULL);
}
