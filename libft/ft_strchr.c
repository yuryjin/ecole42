/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:15:48 by zlucan            #+#    #+#             */
/*   Updated: 2019/09/14 17:31:32 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *location;

	location = (char *)s;
	while (*location != c)
	{
		if (*location == '\0')
		{
			return (NULL);
		}
		location++;
	}
	return (location);
}
