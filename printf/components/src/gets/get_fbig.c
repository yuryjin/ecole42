/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fbig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:51:32 by zlucan            #+#    #+#             */
/*   Updated: 2020/11/17 22:46:49 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		printf_fbig(t_pf_argums *arguments, va_list list,
				char *printval, char *doubleleftover)
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

int		get_fbig(t_pf_argums *arguments, va_list list)
{
	double	argument_double;
	char	*printout;
	int		j;
	char	*doubleleftover;
	int		decimal_width;
	int		count;

	count = 0;
	j = 0;
	argument_double = va_arg(list, double);
	if (argument_double == INFINITY)
	{
		printout = "INF";
		count = printf_s(arguments, printout);
	}
	if (argument_double == NAN)
	{
		printout = "NAN";
		count = printf_s(arguments, printout);
	}
	if (argument_double != INFINITY && argument_double != NAN)
	{
		printout = ft_itoa(argument_double);
		doubleleftover = dissect_float2(argument_double, arguments->precision);
		count = printf_fbig(arguments, list, printout, doubleleftover);
	}
	return (0);
}
