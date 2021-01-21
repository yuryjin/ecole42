/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:25:45 by zlucan            #+#    #+#             */
/*   Updated: 2019/09/23 22:33:42 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	*z;

	z = (char *)src;
	i = 0;
	j = 0;
	while (dest[i] && i < size)
		i++;
	while (((z[j]) && (i + j + 1) < size))
	{
		dest[i + j] = z[j];
		j++;
	}
	if (i != size)
		dest[i + j] = '\0';
	return (i + ft_strlen(z));
}
