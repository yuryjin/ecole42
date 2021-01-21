/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:51:32 by zlucan            #+#    #+#             */
/*   Updated: 2020/11/17 22:53:27 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		printf_d(t_pf_argums *arguments, char *printval)
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
	i = 0;
	int		tab[2] = {len, precisionval};
	arguments->flags & PF_FLAG_ZERO ? subst = '0' : 0;
	if (arguments->flags & PF_FLAG_ZERO && len > precisionval)
		subst = '0';
	if (ft_atoi(printval) < 0 && arguments->flags & PF_FLAG_ZERO &&
		!(arguments->modifier == L))
	{
		write(1, &printval[i], 1);
		i++;
		arguments->outputlen++;
	}
	if (arguments->flags & PF_FLAG_PLUS && ft_atoi(printval) >= 0 &&
		arguments->flags & PF_FLAG_ZERO)
	{
		write(1, "+", 1);
		arguments->outputlen++;
	}
	if (arguments->flags & PF_FLAG_SPACE && ft_atoi(printval) >= 0 &&
		!(arguments->flags & PF_FLAG_PLUS))
	{
		write(1, " ", 1);
		widthval--;
		arguments->outputlen++;
	}
	if (arguments->flags & PF_FLAG_PLUS && ft_atoi(printval) >= 0)
		widthval--;
	while (widthval > ft_max(tab, 2) && !(arguments->flags & PF_FLAG_MINUS))
	{
		if (!(arguments->flags & PF_FLAG_PLUS) && ft_atoi(printval) >= 0)
			subst = ' ';
		if (arguments->flags & PF_FLAG_ZERO && arguments->precision == 0)
		{
			subst = '0';
		}
		write(1, &subst, 1);
		widthval--;
		arguments->outputlen++;
	}
	if (ft_atoi(printval) < 0 && !(arguments->flags & PF_FLAG_ZERO) &&
		!(arguments->modifier == L))
	{
		write(1, &printval[i], 1);
		i++;
		if (ft_atoi(printval) < 0)
			len--;
		arguments->outputlen++;
	}
	if (arguments->flags & PF_FLAG_PLUS && ft_atoi(printval) >= 0 &&
		!(arguments->flags & PF_FLAG_ZERO))
	{
		write(1, "+", 1);
		arguments->outputlen++;
	}
	while (precisionval > len)
	{
		write(1, "0", 1);
		precisionval--;
		widthval--;
		arguments->outputlen++;
	}
	while (printval[i] && !(arguments->dotisused == 1 &&
			ft_atoi(printval) == 0))
	{
		write(1, &printval[i], 1);
		i++;
		arguments->outputlen++;
	}
	if (ft_atoi(printval) < 0 && !(arguments->flags & PF_FLAG_ZERO))
	{
		len++;
	}
	if (arguments->dotisused == 1 && ft_atoi(printval) == 0 &&
		!(arguments->precision == 0))
	{
		write(1, &printval[i], 1);
		i++;
		arguments->outputlen++;
	}
	if (ft_atoi(printval) == 0 && (arguments->dotisused == 1) &&
		arguments->precision == 0 && widthval != 0)
	{
		write(1, " ", 1);
		arguments->outputlen++;
	}
	while (widthval > len && arguments->flags & PF_FLAG_MINUS)
	{
		subst = ' ';
		write(1, &subst, 1);
		widthval--;
		arguments->outputlen++;
	}
	return (0);
}

int		get_d(t_pf_argums *arguments, va_list list)
{
	intmax_t	n;
	char		*printout;
	int			j;

	if (arguments->modifier == NONE || arguments->modifier == L ||
	arguments->modifier == LL ||
	arguments->modifier == J || arguments->modifier == Z)
	{
		arguments->modifier == NONE ? n = va_arg(list, unsigned int) : 0;
		arguments->modifier == L ? n = va_arg(list, unsigned long) : 0;
		arguments->modifier == LL ? n = va_arg(list, unsigned long long) : 0;
		arguments->modifier == J ? n = va_arg(list, uintmax_t) : 0;
		arguments->modifier == Z ? n = va_arg(list, size_t) : 0;
	}
	else
	{
		n = va_arg(list, int);
	}
	arguments->modifier == HH ? n = (char)n : 0;
	arguments->modifier == H ? n = (short)n : 0;
	j = 0;
	if ((unsigned long long)n == -9223372036854775808ULL &&
		arguments->modifier == LL)
	{
		write(1, "-", 1);
		arguments->outputlen++;
	}
	if (arguments->modifier == L)
		printout = ft_itoa2(n);
	else if (arguments->modifier == LL)
	{
		printout = ft_itoa_ull((unsigned long long)n);
	}
	else
		printout = ft_itoa(n);
	printf_d(arguments, printout);
	return (0);
}
