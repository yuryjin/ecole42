/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:39:00 by zlucan            #+#    #+#             */
/*   Updated: 2019/09/20 16:24:45 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
					int c, size_t n)
{
	size_t			i;
	unsigned char	*ccpy1;
	unsigned char	*ccpy2;

	i = 0;
	ccpy1 = (unsigned char *)dst;
	ccpy2 = (unsigned char *)src;
	while (i < n)
	{
		ccpy1[i] = ccpy2[i];
		if (ccpy1[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
