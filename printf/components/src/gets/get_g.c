/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_g.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlucan <zlucan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:51:32 by zlucan            #+#    #+#             */
/*   Updated: 2020/11/17 22:47:07 by zlucan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		get_g(t_pf_argums *arguments, va_list list)
{
	intmax_t n;

	arguments->modifier == NONE ? n = va_arg(list, double) : 0;
	arguments->modifier == L ? n = va_arg(list, long double) : 0;
	write(1, "g\n", 2);
	return (0);
}
