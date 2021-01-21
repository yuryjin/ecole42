/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:45:20 by zlucan            #+#    #+#             */
/*   Updated: 2019/09/24 18:25:27 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*s11;
	char	*s22;
	char	*res;

	s11 = (char *)s1;
	s22 = (char *)s2;
	i = 0;
	if (s11 == NULL || s22 == NULL)
		return (NULL);
	res = (char*)malloc(sizeof(*res) * (ft_strlen(s11) + ft_strlen(s22) + 1));
	if (res == NULL)
		return (NULL);
	while (*s11)
		res[i++] = *s11++;
	while (*s22)
		res[i++] = *s22++;
	res[i] = '\0';
	return (res);
}
