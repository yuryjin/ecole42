/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:00:00 by zlucan            #+#    #+#             */
/*   Updated: 2020/12/09 22:17:21 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int				ft_max(int *tab, int length)
{
	int	i;
	int	max;

	i = 0;
	max = tab[i];
	while (i < length)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

size_t			ft_nbrlen_ll(long long n)
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

char			*ft_itoa_ll(long long n)
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
