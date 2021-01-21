/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_e.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:51:32 by zlucan            #+#    #+#             */
/*   Updated: 2020/12/09 22:11:25 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		printf_e(t_pf_argums *arguments, char *printval, char *doubleleftover)
{
	int		len;
	int		len2;
	int		widthval;
	int		precisionval;
	int		i;
	char	subst;
	int		j;

	j = 0;
	len = ft_strlen(printval);
	len2 = ft_strlen(doubleleftover);
	widthval = arguments->width;
	precisionval = arguments->precision;
	subst = ' ';
	arguments->flags & PF_FLAG_PLUS ? widthval-- : 0;
	while (widthval - precisionval > len && !(arguments->flags & PF_FLAG_MINUS))
	{
		write(1, &subst, 1);
		widthval--;
	}
	arguments->flags & PF_FLAG_PLUS ? write(1, "+", 2) : 0;
	i = 0;
	while (printval[i])
	{
		write(1, &printval[i], 1);
		i++;
	}
	ft_atoi(doubleleftover) != 0 ? write(1, ".", 1) : 0;
	while (len2 > 0)
	{
		write(1, &doubleleftover[j++], 1);
		len2--;
		precisionval--;
	}
	while (precisionval > 0)
	{
		write(1, "0", 1);
		precisionval--;
	}
	return (0);
}

int		dividebyten(double n)
{
	int		i;
	char	*zz;

	zz = ft_itoa(n);
	i = 0;
	while (ft_strlen(ft_itoa(n)) != 1 || zz[0] != '0')
	{
		i++;
		n /= ft_topower(10, i);
	}
	return (0);
}

int		increasebyten(double n)
{
	int		i;
	char	*zz;

	zz = ft_itoa(n);
	i = 0;
	while (ft_strlen(ft_itoa(n)) != 1 || zz[0] != '0')
	{
		i++;
		n *= ft_topower(10, i);
	}
	return (0);
}

int		get_e(t_pf_argums *arguments, va_list list)
{
	double	n;
	char	*printout;
	char	*doubleleftover;
	int		i;

	i = 0;
	arguments->modifier == NONE ? n = va_arg(list, double) : 0;
	arguments->modifier == L ? n = va_arg(list, long double) : 0;
	char	*zz = ft_itoa(n);
	if (ft_strlen(ft_itoa(n)) == 1 && zz[0] != '0')
	{
		printout = ft_itoa(n);
		doubleleftover = dissect_float2(n, 6);
	}
	if (ft_strlen(ft_itoa(n)) != 1 || zz[0] == '0')
	{
		if (n < 1)
		{
			while (n < 1)
			{
				n *= ft_topower(10, 1);
				i++;
			}
			printout = ft_itoa(n);
			doubleleftover = dissect_float2(n, 6);
		}
		if (n > 10)
		{
			i = ft_strlen(ft_itoa(n)) - 1;
			n /= ft_topower(10, i);
			while (ft_strlen(ft_itoa(n)) != 1)
			{
				n /= ft_topower(10, i);
				i++;
			}
			printout = ft_itoa(n);
			doubleleftover = dissect_float2(n, 6);
		}
	}
	return (0);
}
