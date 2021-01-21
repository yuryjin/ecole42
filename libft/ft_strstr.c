/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:50:30 by zlucan            #+#    #+#             */
/*   Updated: 2019/09/24 19:04:22 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*hay;
	char	*nee;

	hay = (char *)haystack;
	nee = (char *)needle;
	i = 0;
	if (nee[0] == '\0')
		return (hay);
	while (hay[i])
	{
		j = 0;
		while (nee[j] == hay[i + j])
		{
			if (nee[j + 1] == '\0')
			{
				return (hay + i);
			}
			j++;
		}
		i++;
	}
	return (0);
}
