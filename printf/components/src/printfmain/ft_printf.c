/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:25:28 by zlucan            #+#    #+#             */
/*   Updated: 2020/11/17 21:54:17 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char				*dissect_float2(double n, int decimal_width)
{
	int		i;
	double	nn;
	int		counter;

	i = (int)n;
	nn = n;
	nn -= i;
	counter = 0;
	while (counter < decimal_width && counter < 10)
	{
		nn *= 10;
		counter++;
	}
	return (ft_itoa(nn));
}

int					checko(const char *str, int i)
{
	while (ft_is_valid_not_conversion(str[i]))
	{
		i++;
	}
	if (ft_is_conversion(str[i]))
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

int					pf_parse_format(const char *str, va_list list)
{
	t_pf_argums		arguments;
	size_t			i;
	ssize_t			j;
	int				count;
	int				okayy;

	okayy = 0;
	arguments.outputlen = 0;
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			i = parsemain(str, i, list, &arguments);
		}
		else
		{
			j = write(1, &str[i++], 1);
			arguments.outputlen++;
			j++;
		}
	}
	return (arguments.outputlen);
}

int					ft_printf(const char *format, ...)
{
	va_list	list;
	int		result;

	va_start(list, format);
	result = pf_parse_format(format, list);
	va_end(list);
	return (result);
}
