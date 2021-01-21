/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:51:32 by zlucan            #+#    #+#             */
/*   Updated: 2020/11/17 23:03:17 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		printf_u(t_pf_argums *arguments, char *printval)
{
	int		len = ft_strlen(printval);
	int		widthval;
	int		precisionval;
	int		i;
	char	subst;

	widthval = arguments->width;
	precisionval = arguments->precision;
	subst = ' ';
	arguments->flags & PF_FLAG_PLUS ? widthval-- : 0;
	arguments->flags & PF_FLAG_ZERO ? subst = '0' : 0;
	int		tab[2] = {len, precisionval};
	while (widthval > ft_max(tab, 2) && !(arguments->flags & PF_FLAG_MINUS))
	{
		write(1, &subst, 1);
		widthval--;
		arguments->outputlen++;
	}
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
	while (widthval > ft_max(tab, 2) && arguments->flags & PF_FLAG_MINUS)
	{
		write(1, &subst, 1);
		widthval--;
		arguments->outputlen++;
	}
	return (0);
}

int		get_u(t_pf_argums *arguments, va_list list)
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
	printout = ft_itoa_ull(n);
	printf_u(arguments, printout);
	return (0);
}
