/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing_getvars.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 21:55:53 by zlucan            #+#    #+#             */
/*   Updated: 2020/11/17 21:57:29 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		getmodifier(const char *str, size_t i, t_pf_argums *arguments)
{
	arguments->modifier = NONE;
	if (str[i] == 'l')
	{
		arguments->modifier = L;
		i++;
		if (str[i] == 'l')
		{
			arguments->modifier = LL;
			i++;
		}
	}
	if (str[i] == 'h')
	{
		arguments->modifier = H;
		i++;
		if (str[i] == 'h')
		{
			arguments->modifier = HH;
			i++;
		}
	}
	str[i] == 'j' ? arguments->modifier = J : 0;
	str[i] == 'z' ? arguments->modifier = Z : 0;
	return (i++);
}

int		getprecision(const char *str, size_t i,
					t_pf_argums *arguments, va_list list)
{
	char	tempstr2[100];
	int		j;

	ft_memset(tempstr2, '\0', ft_strlen(tempstr2));
	arguments->dotisused = 1;
	i++;
	j = 0;
	if (str[i] == '*')
	{
		arguments->precision = va_arg(list, int);
		i++;
	}
	else
	{
		while (ft_isdigit(str[i]))
		{
			tempstr2[j++] = str[i++];
		}
		arguments->precision = ft_atoi(tempstr2);
	}
	return (i);
}

int		getwidth(const char *str, size_t i, t_pf_argums *arguments,
				va_list list)
{
	char	tempstr[100];
	int		j;

	ft_memset(tempstr, '\0', ft_strlen(tempstr));
	j = 0;
	if (str[i] == '*')
	{
		arguments->width = va_arg(list, int);
		i++;
	}
	else
	{
		while (ft_isdigit(str[i]))
		{
			tempstr[j++] = str[i];
			i++;
		}
		arguments->width = ft_atoi(tempstr);
	}
	return (i);
}

int		getflag(const char *str, size_t i, t_pf_argums *arguments)
{
	while (ft_is_flag(str[i]))
	{
		str[i] == '#' ? arguments->flags |= PF_FLAG_HASH : 0;
		str[i] == '0' ? arguments->flags |= PF_FLAG_ZERO : 0;
		str[i] == '-' ? arguments->flags |= PF_FLAG_MINUS : 0;
		str[i] == '+' ? arguments->flags |= PF_FLAG_PLUS : 0;
		str[i] == ' ' ? arguments->flags |= PF_FLAG_SPACE : 0;
		str[i] == '\'' ? arguments->flags |= PF_FLAG_APOSTROPHE : 0;
		i++;
	}
	return (i);
}
