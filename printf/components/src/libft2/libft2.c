/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 22:01:08 by zlucan            #+#    #+#             */
/*   Updated: 2020/11/17 22:06:55 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdlib.h>

int			ft_atoi2(const char *str)
{
	int				sign;
	intmax_t		result;

	sign = 1;
	result = 0;
	while (*str && (*str == ' ' || *str == '\r' || *str == '\n' ||
					*str == '\t' || *str == '\v' || *str == '\f'))
		++str;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		++str;
	}
	return (sign * result);
}

int			ft_isdigit2(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t		ft_nbrlen_ull(unsigned long long n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

char		*ft_itoa_ull(unsigned long long n)
{
	char	*result;
	size_t	i;

	i = ft_nbrlen_ull(n);
	if (!(result = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (n == 0)
		result[0] = '0';
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	result[i] = '\0';
	while (n)
	{
		i--;
		result[i] = n % 10 + '0';
		n /= 10;
	}
	return (result);
}
