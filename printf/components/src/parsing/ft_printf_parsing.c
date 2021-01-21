/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 22:16:31 by zlucan            #+#    #+#             */
/*   Updated: 2020/12/09 22:16:49 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	parsemain(const char *str, size_t i, va_list list, t_pf_argums *arguments)
{
	arguments->flags = 0;
	arguments->width = 0;
	arguments->precision = 0;
	arguments->dotisused = 0;
	arguments->modifier = NONE;
	if (ft_is_valid(str[i]))
	{
		ft_is_flag(str[i]) ? i = getflag(str, i, arguments) : 0;
		ft_isdigit(str[i]) || ft_strchr("*", str[i])
					? i = getwidth(str, i, arguments, list) : 0;
		ft_strchr(".", str[i]) ? i = getprecision(str, i, arguments, list) : 0;
		ft_is_modifier(str[i]) ? i = getmodifier(str, i, arguments) : 0;
		i = gettypes(str, i, arguments, list);
	}
	return (i);
}
