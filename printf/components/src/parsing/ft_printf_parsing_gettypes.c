/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing_gettypes.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 21:58:57 by zlucan            #+#    #+#             */
/*   Updated: 2020/12/09 21:38:58 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		gettypes(const char *str, size_t i,
				t_pf_argums *arguments, va_list list)
{
	if (ft_is_conversion(str[i]))
	{
		arguments->type = str[i];
		str[i] == 'a' ? get_a(arguments, list) : 0;
		str[i] == 'A' ? get_abig(arguments, list) : 0;
		str[i] == 'c' ? get_c(arguments, list) : 0;
		str[i] == 'd' ? get_d(arguments, list) : 0;
		str[i] == 'e' ? get_e(arguments, list) : 0;
		str[i] == 'f' ? get_f(arguments, list) : 0;
		str[i] == 'g' ? get_g(arguments, list) : 0;
		str[i] == 'i' ? get_i(arguments, list) : 0;
		str[i] == 'n' ? get_n(arguments, list) : 0;
		str[i] == 'o' ? get_o(arguments, list) : 0;
		str[i] == 'p' ? get_p(arguments, list) : 0;
		str[i] == '%' ? get_percent(arguments) : 0;
		str[i] == 's' ? get_s(arguments, list) : 0;
		str[i] == 'u' ? get_u(arguments, list) : 0;
		str[i] == 'x' ? get_x(arguments, list) : 0;
		str[i] == 'X' ? get_xbig(arguments, list) : 0;
	}
	i++;
	return (i);
}
