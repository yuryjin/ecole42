/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:51:32 by zlucan            #+#    #+#             */
/*   Updated: 2020/12/09 22:09:21 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		printf_o(t_pf_argums *arguments, char *printval)
{
	int		len;
	int		widthval;
	int		precisionval;
	int		i;
	char	subst;

	len = ft_strlen(printval);
	widthval = arguments->width;
	precisionval = arguments->precision;
	subst = ' ';
	arguments->flags & PF_FLAG_ZERO ? subst = '0' : 0;
	arguments->flags & PF_FLAG_HASH ? widthval-- : 0;
	arguments->flags & PF_FLAG_PLUS ? widthval-- : 0;
	if (ft_atoi(printval) == 0)
		len = 0;
	while (widthval - precisionval > len && !(arguments->flags & PF_FLAG_MINUS))
	{
		write(1, &subst, 1);
		widthval--;
		arguments->outputlen++;
	}
	if (arguments->flags & PF_FLAG_HASH)
	{
		write(1, "0", 1);
		widthval--;
		arguments->outputlen++;
	}
	arguments->flags & PF_FLAG_PLUS ? write(1, "+", 2) : 0;
	while (precisionval > len)
	{
		write(1, "0", 1);
		precisionval--;
		arguments->outputlen++;
	}
	i = 0;
	if (arguments->dotisused != 1 || printval[0] != '0')
	{
		while (printval[i])
		{
			write(1, &printval[i], 1);
			i++;
			arguments->outputlen++;
		}
	}
	widthval = arguments->width;
	arguments->precision != 0 ? widthval-- : 0;
	arguments->flags & PF_FLAG_HASH ? widthval-- : 0;
	while (widthval > len && arguments->flags & PF_FLAG_MINUS)
	{
		subst = ' ';
		write(1, &subst, 1);
		widthval--;
		arguments->outputlen++;
	}
	return (0);
}

char	*dtooct(intmax_t i)
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
		remainder = quotient % 8;
		hexadecimalnum[j++] = 48 + remainder;
		quotient = quotient / 8;
	}
	hexadecimalnum[j] = '\0';
	returnvalue = ft_strrev(hexadecimalnum);
	return (returnvalue);
}

int		get_o(t_pf_argums *arguments, va_list list)
{
	intmax_t	n;
	char		*printout;
	int			j;

	arguments->modifier == NONE ? n = va_arg(list, unsigned int) : 0;
	arguments->modifier == L ? n = va_arg(list, unsigned long) : 0;
	arguments->modifier == LL ? n = va_arg(list, unsigned long long) : 0;
	arguments->modifier == J ? n = va_arg(list, uintmax_t) : 0;
	arguments->modifier == Z ? n = va_arg(list, size_t) : 0;
	arguments->modifier == HH ? n = va_arg(list, unsigned int) : 0;
	arguments->modifier == H ? n = va_arg(list, unsigned int) : 0;
	printout = dtooct(n);
	j = 0;
	printf_o(arguments, printout);
	return (0);
}
