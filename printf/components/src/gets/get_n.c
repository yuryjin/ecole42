/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:51:32 by zlucan            #+#    #+#             */
/*   Updated: 2020/11/17 22:51:01 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		get_n(t_pf_argums *arguments, va_list list)
{
	intmax_t n;

	arguments->modifier == NONE ? n = va_arg(list, int) : 0;
	arguments->modifier == L ? n = va_arg(list, long) : 0;
	arguments->modifier == LL ? n = va_arg(list, long long) : 0;
	arguments->modifier == J ? n = va_arg(list, intmax_t) : 0;
	arguments->modifier == Z ? n = va_arg(list, size_t) : 0;
	arguments->modifier == HH ? n = va_arg(list, int) : 0;
	arguments->modifier == H ? n = va_arg(list, int) : 0;
	write(1, "n", 2);
	return (0);
}
