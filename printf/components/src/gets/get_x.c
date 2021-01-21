/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:51:32 by zlucan            #+#    #+#             */
/*   Updated: 2020/12/09 21:56:51 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*dtox(intmax_t i)
{
	long	quotient;
	long	remainder;
	int		j;
	char	hexadecimalnum[100];
	char	*returnvalue;

	j = 0;
	ft_memset(hexadecimalnum, '\0', ft_strlen(hexadecimalnum));
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

int		printf_zerox(t_pf_argums *arguments, char *xvaluestr)
{
	int		len;
	int		widthval;
	char	subst;

	len = ft_strlen(xvaluestr);
	widthval = arguments->width;
	subst = ' ';
	while (widthval > 0 && !(arguments->flags & PF_FLAG_MINUS))
	{
		write(1, &subst, 1);
		widthval--;
		arguments->outputlen++;
	}
	if (arguments->dotisused == 0)
	{
		write(1, "0", 1);
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

int		printso(t_pf_argums *arguments, char *xvaluestr)
{
	int		len;
	int		widthval;
	int		i;
	char	subst;

	len = ft_strlen(xvaluestr);
	widthval = arguments->width;
	subst = ' ';
	arguments->flags & PF_FLAG_ZERO ? subst = '0' : 0;
	if (xvaluestr[0] == '0')
	{
		printf_zerox(arguments, xvaluestr);
	}
	else
	{
		i = 0;
		if (arguments->precision != 0)
		{
			i = 1;
			len--;
		}
		arguments->flags & PF_FLAG_HASH ? widthval -= 2 : 0;
		if (arguments->flags & PF_FLAG_HASH && ft_atoi(xvaluestr)
			!= 0 && arguments->flags & PF_FLAG_ZERO)
		{
			write(1, "0x", 2);
			arguments->outputlen += 2;
		}
		if (arguments->dotisused == 0)
		{
			while (widthval > len && !(arguments->flags & PF_FLAG_MINUS))
			{
				write(1, &subst, 1);
				widthval--;
				arguments->outputlen++;
			}
		}
		if (arguments->dotisused == 1)
		{
			while (widthval > len + 1 && !(arguments->flags & PF_FLAG_MINUS))
			{
				write(1, &subst, 1);
				widthval--;
				arguments->outputlen++;
			}
		}
		if (arguments->flags & PF_FLAG_HASH && ft_atoi(xvaluestr)
			!= 0 && !(arguments->flags & PF_FLAG_ZERO))
		{
			write(1, "0x", 2);
			arguments->outputlen += 2;
		}
		i = 0;
		while (xvaluestr[i])
		{
			write(1, &xvaluestr[i], 1);
			i++;
			arguments->outputlen++;
		}
		while (widthval > len && arguments->flags & PF_FLAG_MINUS)
		{
			subst = ' ';
			write(1, &subst, 1);
			widthval--;
			arguments->outputlen++;
		}
	}
	return (0);
}

int		get_x(t_pf_argums *arguments, va_list list)
{
	char		*xvaluestr;
	intmax_t	n;

	arguments->modifier == NONE ? n = va_arg(list, unsigned int) : 0;
	arguments->modifier == L ? n = va_arg(list, unsigned long) : 0;
	arguments->modifier == LL ? n = va_arg(list, long long) : 0;
	arguments->modifier == J ? n = va_arg(list, uintmax_t) : 0;
	arguments->modifier == Z ? n = va_arg(list, size_t) : 0;
	arguments->modifier == HH ? n = va_arg(list, unsigned int) : 0;
	arguments->modifier == H ? n = va_arg(list, unsigned int) : 0;
	if (n != 0)
	{
		xvaluestr = dtox(n);
		printso(arguments, xvaluestr);
	}
	if (n == 0)
	{
		printso(arguments, "0");
	}
	return (0);
}
