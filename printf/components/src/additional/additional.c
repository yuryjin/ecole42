/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 21:48:13 by zlucan            #+#    #+#             */
/*   Updated: 2020/12/09 21:49:00 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int						ft_is_valid2(const char c)
{
	return (ft_isdigit(c) ||
			ft_strchr("dDioOuUxXeEfFgGaAcCsSpn%hljz#0-+' $*.", c) != NULL);
}

int						ft_is_not_type(const char c)
{
	return (ft_isdigit(c) || ft_strchr("hljz#0-+' $*.", c) != NULL);
}

inline extern int		ft_is_type(const char c)
{
	return (ft_strchr("dDioOuUxXeEfFgGaAcCsSpn%", c) != NULL);
}

char					*ft_strchr(const char *s, int c)
{
	char *str;

	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return (str);
}
