/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ebig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:51:32 by zlucan            #+#    #+#             */
/*   Updated: 2020/12/09 22:10:46 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	get_ebig(t_pf_argums *arguments, va_list list)
{
	intmax_t n;

	arguments->modifier == NONE ? n = va_arg(list, double) : 0;
	arguments->modifier == L ? n = va_arg(list, long double) : 0;
	write(1, "E\n", 2);
	return (0);
}
