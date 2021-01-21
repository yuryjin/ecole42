/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:51:32 by zlucan            #+#    #+#             */
/*   Updated: 2020/12/09 22:08:39 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		printf_s(t_pf_argums *arguments, char *printval)
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
	precisionval = arguments->precision;
	if (len == 0)
	{
		while (widthval > 0)
		{
			write(1, &subst, 1);
			widthval--;
			arguments->outputlen++;
		}
	}
	if (len != 0)
	{
		while (widthval > len - precisionval &&
				!(arguments->flags & PF_FLAG_MINUS))
		{
			write(1, &subst, 1);
			widthval--;
			arguments->outputlen++;
		}
		if (precisionval == 0)
		{
			while (printval[i])
			{
				write(1, &printval[i], 1);
				i++;
				precisionval--;
				arguments->outputlen++;
			}
		}
		if (precisionval > len)
		{
			while (printval[i])
			{
				write(1, &printval[i], 1);
				i++;
				precisionval--;
				arguments->outputlen++;
			}
		}
		if (precisionval < len)
		{
			while (precisionval > 0)
			{
				write(1, &printval[i], 1);
				i++;
				precisionval--;
				arguments->outputlen++;
			}
		}
		precisionval = arguments->precision;
		while (widthval > len - precisionval &&
				arguments->flags & PF_FLAG_MINUS)
		{
			write(1, &subst, 1);
			widthval--;
			arguments->outputlen++;
		}
	}
	return (0);
}

int		get_s(t_pf_argums *arguments, va_list list)
{
	char	*argstr;
	int		j;
	int		count;

	count = 0;
	j = 0;
	argstr = va_arg(list, char *);
	if (argstr == NULL)
	{
		argstr = ("(null)");
	}
	count = printf_s(arguments, argstr);
	return (count);
}
