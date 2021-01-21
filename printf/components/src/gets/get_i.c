/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:51:32 by zlucan            #+#    #+#             */
/*   Updated: 2020/11/17 22:50:40 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		printf_i(t_pf_argums *arguments, char *printval)
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
	arguments->flags & PF_FLAG_PLUS ? widthval-- : 0;
	while (widthval - precisionval + len > len &&
			!(arguments->flags & PF_FLAG_MINUS))
	{
		write(1, &subst, 1);
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
	while (printval[i])
	{
		write(1, &printval[i], 1);
		i++;
		arguments->outputlen++;
	}
	while (widthval - precisionval + len > len &&
			arguments->flags & PF_FLAG_MINUS)
	{
		write(1, &subst, 1);
		widthval--;
		arguments->outputlen++;
	}
	return (0);
}

int		get_i(t_pf_argums *arguments, va_list list)
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
	j = 0;
	printout = ft_itoa(n);
	printf_i(arguments, printout);
	return (0);
}
