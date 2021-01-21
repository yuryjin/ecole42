/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:51:56 by zlucan            #+#    #+#             */
/*   Updated: 2019/09/23 22:12:25 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		len;
	char	*s11;

	s11 = (char *)s;
	if (!s11)
		return (NULL);
	start = 0;
	while (s11[start] && (s11[start] == ' ' ||
			s11[start] == '\n' || s11[start] == '\t'))
		start++;
	end = ft_strlen(s11);
	while (start < end && (s11[end - 1] == ' ' ||
			s11[end - 1] == '\n' || s11[end - 1] == '\t'))
		end--;
	if (start == end)
		return (ft_strnew(1));
	len = end - start;
	return (ft_strsub(s11, start, len));
}
