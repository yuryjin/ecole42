/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:00:21 by zlucan            #+#    #+#             */
/*   Updated: 2019/09/24 18:25:31 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int j;
	unsigned int i;

	if (!*needle)
		return ((char*)haystack);
	j = 0;
	while (haystack[j] != '\0' && (size_t)j < len)
	{
		if (haystack[j] == needle[0])
		{
			i = 1;
			while (needle[i] != '\0' && haystack[j + i] == needle[i] &&
					(size_t)(j + i) < len)
				++i;
			if (needle[i] == '\0')
				return ((char*)&haystack[j]);
		}
		++j;
	}
	return (0);
}
