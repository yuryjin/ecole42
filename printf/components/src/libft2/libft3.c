/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 22:00:46 by zlucan            #+#    #+#             */
/*   Updated: 2020/12/09 22:17:39 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static		size_t	ft_nbrlen2(intmax_t n)
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

char				*ft_itoa2(intmax_t n)
{
	char	*result;
	size_t	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_nbrlen2(n);
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

size_t				ft_strlen2(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char				*ft_strrev2(char *str)
{
	int		i;
	int		length;
	char	buff;

	i = 0;
	length = ft_strlen(str);
	while (length - 1 > i)
	{
		buff = str[i];
		str[i] = str[length - 1];
		str[length - 1] = buff;
		length--;
		i++;
	}
	return (str);
}

double				ft_topower2(int num, int pow)
{
	double	res;
	int		i;

	if (pow == 0)
		return (-1);
	i = -1;
	res = 1.0;
	if (pow < 0)
	{
		while (++i < pow * (-1))
			res *= (double)num;
		res = 1 / res;
	}
	else
		while (++i < pow)
			res *= (double)num;
	return (res);
}
