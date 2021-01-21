/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_abig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:51:32 by zlucan            #+#    #+#             */
/*   Updated: 2020/12/09 21:41:00 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*dtoxpoint_big(intmax_t i)
{
	double	quotient;
	double	remainder;
	int		j;
	char	hexadecimalnum[100];
	char	*returnvalue;

	j = 0;
	if (i == 0)
		return ("0");
	quotient = i;
	while (quotient != 0)
	{
		remainder = quotient / 16;
		if (remainder < 10)
			hexadecimalnum[j++] = 48 + remainder;
		else
			hexadecimalnum[j++] = 87 + remainder;
		quotient = quotient / 16;
	}
	returnvalue = ft_strrev(hexadecimalnum);
	return (returnvalue);
}

double	ft_topower_big(int num, int pow)
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

int		whileless_big(double n)
{
	int i;

	i = 0;
	while (n < 2)
	{
		n *= 2;
		i++;
	}
	return (i);
}

int		whilemore_big(double n)
{
	int i;

	i = 0;
	while (n > 2)
	{
		n /= 2;
		i++;
	}
	return (i);
}

char	*dtox_big(intmax_t i)
{
	long	quotient;
	long	remainder;
	int		j;
	char	hexadecimalnum[100];
	char	*returnvalue;

	j = 0;
	if (i == 0)
		return ("0");
	quotient = i;
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			hexadecimalnum[j++] = 48 + remainder;
		else
			hexadecimalnum[j++] = 87 + remainder;
		quotient = quotient / 16;
	}
	hexadecimalnum[j] = '\0';
	returnvalue = ft_strrev(hexadecimalnum);
	return (returnvalue);
}

int		hextodec_float_big(double input)
{
	double	placeholder;
	int		x;
	int		i;
	int		bool1;

	placeholder = input;
	bool1 = 0;
	x = 1;
	i = 16;
	placeholder -= 1;
	while (bool1 != 1)
	{
		x++;
		if (placeholder * i / x == 1)
			bool1 = 1;
		if (x == i)
		{
			i *= 16;
		}
	}
	return (x);
}

int		get_abig(t_pf_argums *arguments, va_list list)
{
	double	n;
	int		i;
	char	plusminussign;
	int		val;
	char	*str;

	plusminussign = '+';
	i = 0;
	arguments->modifier == NONE ? n = va_arg(list, double) : 0;
	arguments->modifier == L ? n = va_arg(list, long double) : 0;
	if (n > 2)
	{
		i = whilemore_big(n);
		n = n / ft_topower_big(2, i);
		plusminussign = '+';
	}
	if (n > 2)
	{
		i = whileless_big(n);
		n = n / ft_topower_big(2, -i);
		plusminussign = '-';
	}
	val = hextodec_float_big(n);
	str = dtoxbig(val);
	ft_printf("0X1.%sP%c%d", str, plusminussign, i);
	return (0);
}
