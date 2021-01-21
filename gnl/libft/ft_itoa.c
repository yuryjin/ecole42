/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:34:49 by zlucan            #+#    #+#             */
/*   Updated: 2019/09/24 18:25:31 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	size_t	ft_nbrlen(int n)
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

char			*ft_itoa(int n)
{
	char	*result;
	size_t	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_nbrlen(n);
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
