/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 19:31:40 by zlucan            #+#    #+#             */
/*   Updated: 2019/09/23 22:12:25 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	size_t	i;
	char	*s11;
	char	*s22;

	s11 = (char *)s1;
	s22 = (char *)s2;
	i = 0;
	if (s11 == '\0' || s22 == '\0')
		return (0);
	if (ft_strlen(s11) != ft_strlen(s22))
		return (0);
	while (s11[i] && s22[i])
	{
		if (s11[i] != s22[i])
			return (0);
		i++;
	}
	return (1);
}
